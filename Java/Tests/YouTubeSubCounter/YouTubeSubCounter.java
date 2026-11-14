/*
 * YouTube Sub Counter Test
 *
 * Modified: 2026-11-14 11:00
 */

import java.net.URI;
import java.net.http.*;
import java.util.*;
import java.util.regex.*;

public class YouTubeSubCounter {
    // My 3 channel IDs
    private static String[] channelIDs = {
        "UC39fS5Y68tESUqZ7EtqRq-g", // Chris Elison Gaming
        "UCuekDids28qhgKr0H3Y7Kvg", // Chris Elison Electronics
        "UC_fmDEOYu0ZO01e3mX89FWQ"  // Chris Elison Tech
    };
    
    // Create a secret key object to keep my API key out of this file
    private static YTSecret secretKey = new YTSecret();

    private static String key = secretKey.getKey(); 
        
    // Channel counts and total
    private static int total = 0;

    private static String subCount = "";

    public static void main(String[] args) {
        System.out.println("YouTube Sub Counter 0.1 by Chris Elison\n");

        System.out.println("Getting stats for channels:");
        
        for (int i=0; i< channelIDs.length; i++) {
            total = total + getChannelCount(channelIDs[i]);
        }

        System.out.println("Total subscribers: " + total);
    }

    private static int getChannelCount(String chanID) {
        int channelCount;
        
        String url = String.format(
            "https://www.googleapis.com/youtube/v3/channels?part=statistics&id=%s&key=%s",
            chanID, key
        );

        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
            .uri(URI.create(url))
            .GET()
            .build();

        try {
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            
            if (response.statusCode() == 200) {
                String json = response.body();
                
                // Light regex extraction to avoid heavy external JSON dependencies for simple fields
                Pattern pattern = Pattern.compile("\"subscriberCount\"\\s*:\\s*\"([^\"]+)\"");
                Matcher matcher = pattern.matcher(json);
                
                if (matcher.find()) {
                    subCount = matcher.group(1);
                    System.out.println("Subscriber Count: " + subCount);
                } else {
                    System.out.println("Subscriber count not found (it might be hidden).");
                    System.exit(0);
                }
            } else {
                System.out.println("API Error: HTTP " + response.statusCode());
                //System.out.println(response.body());
                System.exit(0);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        channelCount = Integer.parseInt(subCount);

        return channelCount;
    }
}
