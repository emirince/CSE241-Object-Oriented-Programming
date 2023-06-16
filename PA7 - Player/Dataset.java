import java.util.ArrayList;
import java.util.List;

public class Dataset{
    
    public List<Dataset> objects;   //List of objects
    private List<Observer> observers;   //List of players and viewers

    //Constructor
    public Dataset(){
        objects = new ArrayList<>();
        observers = new ArrayList<>();
    }

    //Function that adds objects to list
    public void add(Dataset dataset){
        objects.add(dataset);
        updateAddDataset(dataset);
    }

    //Function that removes objects from list
    public void remove(Dataset dataset) {
        objects.remove(dataset);
        updateRemoveDataset(dataset);
    }

    //Function that register a viewer to observers list
    public void register(Viewer viewer) {
        observers.add(viewer);
    }

    //Function that unregister a viewer from observers list
    public void unregister(Viewer viewer) {
        observers.remove(viewer);
    }

    //Function that register a player to observers list
    public void register(Player player) {
        observers.add(player);
    }

    //Function that unregister a player from observers list
    public void unregister(Player player) {
        observers.remove(player);
    }

    //Function that notifys the observers if an item is added to object list
    public void updateAddDataset(Dataset dataset) {
        for (int i = 0 ; i < observers.size() ; i++) {
            if(dataset instanceof Playable)     
                observers.get(i).updateAdd((Playable)dataset);  //This function works is item is playable
            else if(dataset instanceof NonPlayable)
                observers.get(i).updateAdd((NonPlayable)dataset);   //This function works is item is nonplayable
        }
    }

    //Function that notifys the observers if an item is removed from object list
    public void updateRemoveDataset(Dataset dataset) {
        for (int i = 0 ; i < observers.size() ; i++) {
            if(dataset instanceof Playable)
                observers.get(i).updateRemove((Playable)dataset);   //This function works is item is playable
            else if(dataset instanceof NonPlayable)
                observers.get(i).updateRemove((NonPlayable)dataset);    //This function works is item is nonplayable
        }
    }

    public void info(){
    }

    public String getType() {
        return "Type";
    }
}