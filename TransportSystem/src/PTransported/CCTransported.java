package PTransported;

public abstract class CCTransported implements IFTransported {
    protected int ID; 
    protected int cargoID; 
    protected int cargoTypeID;
    protected double Money;
    public int getCargoID(){
    	return cargoID;
    }
    public int getCargoTypeID(){
    	return cargoTypeID;
    }
    public double getMoney(){
    	return Money;
    }
}
