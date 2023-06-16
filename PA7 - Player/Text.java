import java.util.ArrayList;
import java.util.List;

public class Text extends Dataset implements NonVisual, NonPlayable{
    private String textName;
    private String otherInfo;

    //Constructor
    public Text(String textName_, String otherInfo_){
        textName = textName_;
        otherInfo = otherInfo_;
    }

    //Prints the infos about Text object
    @Override
    public void info() {
        System.out.println("Info: " + textName + ", " + otherInfo);
    }
    
    @Override
    public void view(){
        System.out.println(textName);
    }

    //Getters
    public String getName(){
        return textName;
    }

    public String getOtherInfo(){
        return otherInfo;
    }

    @Override
    public String getType(){
        return "Text";
    }
}