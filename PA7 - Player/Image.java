import java.util.ArrayList;
import java.util.List;

public class Image extends Dataset implements Visual, NonPlayable{
    private String imageName;
    private String dimensonInfo;
    private String otherInfo;

    //Constructor
    public Image(String imageName_, String dimensionInfo_, String otherInfo_){
        imageName = imageName_;
        dimensonInfo = dimensionInfo_;
        otherInfo = otherInfo_;
    }

    //Prints the infos about Image object
    @Override
    public void info() {
        System.out.println("Info: " + imageName + ", " + dimensonInfo + ", " + otherInfo);
    }

    @Override 
    public void view() {
        System.out.println(imageName);
    }

    //Getters
    public String getName() {
        return imageName;
    }

    public String getDimension() {
        return dimensonInfo;
    }
    
    public String getOtherInfo() {  
        return otherInfo;
    }

    @Override
    public String getType() {
        return "Image";
    }
}