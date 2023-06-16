import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        //It creates a new Dataset object
        Dataset ds = new Dataset();

        //It creates new player and viewer objects
        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        //Player and Viewer objects are registered to dataset object
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        //Image, Text, Audio and Video objects are added to Dataset object
        ds.add(new Image("imagename1", "dimension info1", "otherinfo1"));
        ds.add(new Image("imagename2", "dimension info2", "otherinfo2"));
        ds.add(new Image("imagename3", "dimension info3", "otherinfo3"));
        ds.add(new Image("imagename4", "dimension info4", "otherinfo4"));
        ds.add(new Image("imagename5", "dimension info5", "otherinfo5"));
        ds.add(new Audio("audioname1", "duration1", "otherinfo1"));
        ds.add(new Audio("audioname2", "duration2", "otherinfo2"));
        ds.add(new Audio("audioname3", "duration3", "otherinfo3"));
        ds.add(new Video("videoname1", "duration1", "otherinfo1"));
        ds.add(new Video("videoname2", "duration2", "otherinfo2"));
        ds.add(new Video("videoname3", "duration3", "otherinfo3"));
        ds.add(new Text("textname1", "otherinfo1"));
        ds.add(new Text("textname2", "otherinfo2"));
        ds.add(new Text("textname3", "otherinfo3"));

        //We play the currently playing object
        Playable po = p1.currently_playing();
        po.info();

        //We view the currently viewing object
        NonPlayable np = v1.currently_viewing();
        np.info();

        //The currently played playing object is removed from playlist
        ds.remove((Dataset)po);

        //Prints the whole items of playlist
        p1.show_list();

        //Prints the whole items of viewlist
        v1.show_list();

        //Plays the next Playable on the playlist
        p1.next("Audio");
        p1.next("Audio");
        p1.next("Audio");
        p1.next("Video");
        p1.next("Video");
        p1.next("Audio");        

        //Plays the next NonPlayable object on the viewlist
        v1.next("Text");
        v1.next("Text");
        v1.next("Image");
        v1.next("Image");
        v1.next("Image");
        v1.next("Text");


    }
}
