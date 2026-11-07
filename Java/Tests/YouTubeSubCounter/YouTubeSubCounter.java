import java.util.*;

public class YouTubeSubCounter {
    // My 3 channel IDs
    private static String[] channelIDs = {
        "abc123456", // Chris Elison Gaming
        "zxc126734", // Chris Elison Electronics
        "bnm654321"  // Chris Elison Tech
    };
    
    // Create a secret key object to keep my API key out of this file
    private static YTSecret secretKey = new YTSecret();

    // Channel counts and total
    private static int channel1Count, channel2Count, channel3Count, total = 0;

    public static void main(String[] args) {
        System.out.println("YouTube Sub Counter 0.1 by Chris Elison\n");
        System.out.println("YT API key: " + secretKey.getKey() + "\n");

        System.out.println("Getting stats for channels:");
        
        total = getChannelCounts();

        System.out.println("Total subscribers: " + total);
    }

    private static int getChannelCounts() {
        for (int i=0; i<channelIDs.length; i++) {
            System.out.println("\t" + channelIDs[i]);
        }

        channel1Count = 504;
        channel2Count = 85;
        channel3Count = 2;

        return channel1Count + channel2Count + channel3Count;
    }
}
