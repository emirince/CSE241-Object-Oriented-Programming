import java.util.ArrayList;
import java.util.List;

public class Viewer implements Observer{

    private List<NonPlayable> viewlist;     //List of nonplayable objects's list
    private int currentIndex;      //This variable helps us to save current index

    //Constructor
    public Viewer() {
        viewlist = new ArrayList<>();
        currentIndex = 0;
    }

    //Prints the whole viewlist
    public void show_list() {
        System.out.println("Viewlist");
        if (viewlist.size() == 0){      //If list is empty, an exception is thrown
            throw new EmptyList();
        }
        else {
            for (NonPlayable obj : viewlist){       //If its not empty, items are printed
                obj.view();
            }
        }
    }

    public NonPlayable currently_viewing() {
        if (viewlist.size() == 0) {     //If list is empty, an exception is thrown
            throw new EmptyList();
        }
        else {
            return viewlist.get(currentIndex);  //If its not empty, the current index's item is returned
        }
    }

    public void updateAdd(NonPlayable nonplayable){     //It updates the viewlist when an item is added
        viewlist.add(nonplayable);
    }

    public void updateRemove(NonPlayable nonplayable){  //It updates the viewlist when an item is removed
        nextToRemove();     
        viewlist.remove(nonplayable);
    }

    
    public void updateAdd(Playable playable){}
    
    public void updateRemove(Playable playable){}

    public void next(String type) {
        boolean found = false;

        if (viewlist.size() == 0) {     //If list is empty, an exception is thrown
            throw new EmptyList();
        }

        else if (type.equals("Image")) {        
            for(int i = currentIndex + 1 ; i < viewlist.size() ; i++) {         //It checks the rest of the list after current index
                if (viewlist.get(i) instanceof Image) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently viewing: ");
                    currently_viewing().view();         
                    break;
                }
            }
            if(!found) {        //If it couldn't found at the rest of the list, the previous items of the current index's item is searched
                for(int i = 0 ; i < currentIndex ; i++) {
                    if (viewlist.get(i) instanceof Image) {
                        currentIndex = i;
                        System.out.print("Currently viewing: ");
                        currently_viewing().view();
                        break;
                    }
                }
            }
        }
        else if (type.equals("Text")) {
            for(int i = currentIndex + 1 ; i < viewlist.size() ; i++) {         //It checks the rest of the list after current index
                if (viewlist.get(i) instanceof Text) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently viewing: ");
                    currently_viewing().view();
                    break;
                }
            }   
            if(!found) {            //If it couldn't found at the rest of the list, the previous items of the current index's item is searched
                for(int i = 0 ; i < currentIndex ; i++) {
                    if (viewlist.get(i) instanceof Text) {
                        currentIndex = i;
                        System.out.print("Currently viewing: ");
                        currently_viewing().view();
                        break;
                    }
                }
            }
        }
    }

    public void nextToRemove() {        //If the current index is reach at the end of the list, the index is set to 0
        if(currentIndex == viewlist.size()-1){
            currentIndex = 0;
        }
    }

    public void previous(String type) {

        boolean found = false;

        if (viewlist.size() == 0) {     //If list is empty, an exception is thrown
            throw new EmptyList();
        }

        else if (type.equals("Image")) {
            for(int i = currentIndex - 1 ; i >= 0 ; i--) {      //It checks the previous items of the current index 
                if (viewlist.get(i) instanceof Image) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently viewing: ");
                    currently_viewing().view();
                    break;
                }
            }
            if(!found) {
                for(int i = viewlist.size()-1 ; i > currentIndex ; i--) {           //If it couldn't found at through the previous items of the list, the rest of the list is searched
                    if (viewlist.get(i) instanceof Image) {
                        currentIndex = i;
                        System.out.print("Currently viewing: ");
                        currently_viewing().view();
                        break;
                    }
                }
            }
        }
        else if (type.equals("Text")) {
            for(int i = currentIndex - 1 ; i >= 0 ; i--) {          //It checks the previous items of the current index 
                if (viewlist.get(i) instanceof Text) {
                    found = true;
                    currentIndex = i;
                    System.out.print("Currently viewing: ");
                    currently_viewing().view();
                    break;
                }
            }
            if(!found) {
                for(int i = viewlist.size()-1 ; i > currentIndex ; i--) {           //If it couldn't found at through the previous items of the list, the rest of the list is searched
                    if (viewlist.get(i) instanceof Text) {
                        currentIndex = i;
                        System.out.print("Currently viewing: ");
                        currently_viewing().view();
                        break;
                    }
                }
            }
        }
    }
}