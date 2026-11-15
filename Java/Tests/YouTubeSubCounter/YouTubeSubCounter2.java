/*
 * YouTube Sub Counter Test 2 - 3 channels in one API call!
 *
 * Modified: 2026-11-15 10:30
 *
 */

import java.net.URI;
import java.net.http.*;
import java.util.*;
import java.util.regex.*;

public class YouTubeSubCounter2 {
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

    private static Map<String, String> subscriberMap = new HashMap<>();
        
    public static void main(String[] args) {
        System.out.println("YouTube Sub Counter 0.1 by Chris Elison\n");

        System.out.println("Getting stats for channels:");

        // Connect to the API and get channel stats
        getChannelStats();
        
        // Print out channel stats
        subscriberMap.forEach((id, subs) -> System.out.println("Channel: " + id + " => Subscribers: " + subs));

        // Add up subscriber count total
        subscriberMap.forEach((id, subs) -> total = total + Integer.parseInt(subs));

        System.out.println("\nTotal subscribers: " + total);
    }

    private static void getChannelStats() {
        int channelCount;
       
        String idParam = String.join(",", channelIDs);

        String url = String.format(
            "https://www.googleapis.com/youtube/v3/channels?part=statistics&id=%s&key=%s",
            idParam, key
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
                
                Pattern pattern = Pattern.compile("\"id\"\\s*:\\s*\"([^\"]+)\"[^}]*?\"subscriberCount\"\\s*:\\s*\"([^\"]+)\"");
                Matcher matcher = pattern.matcher(json);

                while (matcher.find()) {
                    String id = matcher.group(1);
                    String subCount = matcher.group(2);
                    subscriberMap.put(id, subCount);
                }
            } else {
                System.out.println("HTTP error!");
                System.exit(0);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
