public interface Observer {
    public void updateAdd(Playable playable);
    public void updateRemove(Playable playable);

    public void updateAdd(NonPlayable nonplayable);
    public void updateRemove(NonPlayable nonplayable);

}
