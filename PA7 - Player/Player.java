import java.util.ArrayList;
import java.util.List;

public class Player implements Observer{

    private List<Playable> playlist;       //List of playable objects's list
    private int currentIndex;       //This variable helps us to save current index

    //Constructor
    public Player() { 
        playlist = new ArrayList<>();
        currentIndex = 0;
    }

    //Prints the whole playlist
    public void show_list() {
        System.out.println("Playlist");
        if (playlist.size() == 0){      //If list is empty, an exception is thrown
            throw new EmptyList();
        }
        else {
            for (Playable obj : playlist){
                obj.play();
            }
        }
    }

    public Playable currently_playing() {
        if (playlist.size() == 0) {     //If list is empty, an exception is thrown
            throw new EmptyList();  
        }
        else {
            return playlist.get(currentIndex);      //If its not empty, the current index's item is returned
        }
    }
    
    public void updateAdd(Playable playable){        //It updates the playlist when an item is added
        playlist.add(playable);
    }

    public void updateRemove(Playable playable){    //It updates the playlist when an item is removed            
        nextToRemove();
        playlist.remove(playable);
    }

    public void updateAdd(NonPlayable nonplayable){}

    public void updateRemove(NonPlayable nonplayable){}
    
    public void nextToRemove() {        //If the current index is reach at the end of the list, the index is set to 0
        if(currentIndex == playlist.size()-1){
            currentIndex = 0;
        }
    }

    public void next(String type) {
        boolean found = false;
        
        if (playlist.size() == 0) {     //If list is empty, an exception is thrown
            throw new EmptyList();
        }
        else if (type.equals("Audio")) {
            for(int i = currentIndex + 1 ; i < playlist.size() ; i++) {     //It checks the rest of the list after current index
                if (playlist.get(i) instanceof Audio) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently playing: ");
                    currently_playing().play();
                    break;
                }
            }
            if(!found) {        //If it couldn't found at the rest of the list, the previous items of the current index's item is searched
                for(int i = 0 ; i < currentIndex ; i++) {
                    if (playlist.get(i) instanceof Audio) {
                        found = true;
                        currentIndex = i;
                        System.out.print("Currently playing: ");
                        currently_playing().play();
                        break;
                    }
                }
            }
        }
        else if (type.equals("Video")) {         //It checks the rest of the list after current index
            for(int i = currentIndex + 1 ; i < playlist.size() ; i++) {
                if (playlist.get(i) instanceof Video) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently playing: ");
                    currently_playing().play();
                    break;
                }
            }
            if(!found) {        //If it couldn't found at the rest of the list, the previous items of the current index's item is searched
                for(int i = 0 ; i < currentIndex ; i++) {
                    if (playlist.get(i) instanceof Video) {
                        found = true;
                        currentIndex = i;
                        System.out.print("Currently playing: ");
                        currently_playing().play();
                        break;
                    }
                }
            }
        }
    }

    public void previous(String type) {
        boolean found = false;

        if (playlist.size() == 0) {      //If list is empty, an exception is thrown
            throw new EmptyList();
        }

        else if (type.equals("Audio")) {
            for(int i = currentIndex - 1 ; i >= 0 ; i--) {      //It checks the previous items of the current index 
                if (playlist.get(i) instanceof Audio) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently playing: ");
                    currently_playing().play();
                    break;
                }
            }
            if(!found) {
                for(int i = playlist.size()-1 ; i > currentIndex ; i--) {       //If it couldn't found at through the previous items of the list, the rest of the list is searched
                    if (playlist.get(i) instanceof Audio) {
                        found = true;
                        currentIndex = i;
                        System.out.print("Currently playing: ");
                        currently_playing().play();
                        break;
                    }
                }
            }
        }
        else if (type.equals("Video")) {
            for(int i = currentIndex - 1 ; i >= 0 ; i--) {      //It checks the previous items of the current index 
                if (playlist.get(i) instanceof Video) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently playing: ");
                    currently_playing().play();
                    break;
                }
            }
            if(!found) {
                for(int i = playlist.size()-1 ; i > currentIndex ; i--) {       //If it couldn't found at through the previous items of the list, the rest of the list is searched
                    if (playlist.get(i) instanceof Video) {
                        found = true;
                        currentIndex = i;
                        System.out.print("Currently playing: ");
                        currently_playing().play();
                        break;
                    }
                }
            }
        }
    }
}