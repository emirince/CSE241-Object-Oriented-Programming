import java.util.ArrayList;
import java.util.List;

public class Video extends Dataset implements Visual, Playable{
    private String videoName;
    private String duration;
    private String otherInfo;

    //Constructor
    public Video(String videoName_, String duration_, String otherInfo_){
        videoName = videoName_;
        duration = duration_;
        otherInfo = otherInfo_;
    }

    //Prints the infos about Video object
    @Override
    public void info() {
        System.out.println("Info: " + videoName + ", " + duration + ", " + otherInfo);
    }

    @Override
    public void play() {
        System.out.println(videoName);
    }

    //Getters
    public String getName(){
        return videoName;
    }

    public String getDuration(){
        return duration;
    }
    
    public String getOtherInfo(){
        return otherInfo;
    }
    
    @Override
    public String getType(){
        return "Video";
    }
}