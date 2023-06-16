import java.util.ArrayList;
import java.util.List;

public class Audio extends Dataset implements NonVisual, Playable{
    private String audioName;
    private String duration;
    private String otherInfo;

    //Constructor
    public Audio(String audioName_, String duration_, String otherInfo_){
        audioName = audioName_;
        duration = duration_;
        otherInfo = otherInfo_;
    }

    //Prints the infos about Audio object
    @Override
    public void info() {
        System.out.println("Info: " + audioName + ", " + duration + ", " + otherInfo);
    }

    @Override 
    public void play() {
        System.out.println(audioName);
    }

    //Getters
    public String getName() {
        return audioName;
    }

    public String getDuration() {
        return duration;
    }
    
    public String getOtherInfo() {
        return otherInfo;
    }

    @Override
    public String getType() {
        return "Audio";
    }
}