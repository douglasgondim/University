public class Hotel {
    private long rooms;
    private double[] price = new double[4];
    private char[] name = new char[50];
    private boolean occupation[];
    private char room_types[];
    
    
    public Hotel(char[] namee, long num_rooms, char[] types) {
        name = namee;
        rooms = num_rooms;
        room_types = types;
                
    }
    
    public boolean isFreeRoom(long i) {
        if(occupation[(int) i]==true) {
            return false;        
        }else {
            return true;
        }        
        
    }
    
    public double priceRoom(long i) {
        if(room_types[(int) i]=='d') {
            return price[0];
        }else if(room_types[(int) i]=='c') {
            return price[1];
        }else if(room_types[(int) i]=='b') {
            return price[2];
        }else if(room_types[(int) i]=='a') {
            return price[3];
        }
        return i;
    }
    
    public boolean occupiedRoom(long i) {
        if(occupation[(int) i]==true) {
            return true;
        }else {
            return false;
        }
        
    }
    public boolean freeRoom(long i) {
        if(occupation[(int) i]==true) {
            occupation[(int) i] = false;
        }
        return false;
    }
    
    
}


//---------------------------------------------------------------//
//---------------------------------------------------------------//



public class Client {
    private char[] name = new char[200];
    private double money;
    
    public Client(char[] namee, double moneyy) {
        name = namee;
        money = moneyy;        
    }
    
    public boolean canPay(double value) {
        if(value<money) {
            return true;
        }else {
            return false;
        }
    }
    private boolean pay(double value) {
        if(canPay(value) == true) {
            money -= value;
            return true;
        }else
            return false;        
    }
    
    
}

