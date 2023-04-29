// Developed and maintained by Himanshu, Ishan and Gaurav at 29/04/2023

import java.util.*;
import java.time.LocalTime;
class Main
{
    int text,colour;
    double phOfSoil,waterAmount,fertiliserAmount,tubewellLevel=10000000,maxTubewell = 10000000, charge=100;
    boolean acidicFertiliser=false, basicFertiliser=false;
    void calcph()
    {
        Scanner k = new Scanner(System.in);
        double ph=-1;
        System.out.println("\n To know about the Soil Texture, please :");
        System.out.println(" Enter 1 for Sandy Soil");
        System.out.println(" Enter 2 for Clay Soil");
        System.out.println(" Enter 3 for Loam  Soil");
        int a = k.nextInt();
        System.out.println("\n To know about the colour of the soil, please :");
        System.out.println(" Enter 1 for Black Soil");
        System.out.println(" Enter 2 for Red Soil");
        System.out.println(" Enter 3 for Yellow Soil");
        int b = k.nextInt();
        
        text =a; colour=b;
        if(a==1 && b==1)
        ph=7.1;
        if(a==1 && b==2)
        ph=7.2;
        if(a==1 && b==3)
        ph=4;
        if(a==2 && b==1)
        ph=5.4;
        if(a==2 && b==2)
        ph=5.5;
        if(a==2 && b==3)
        ph=7.8;
        if(a==3 && b==1)
        ph=6;
        if(a==3 && b==2)
        ph=6.4;
        if(a==3 && b==3)
        ph=5.2;
        phOfSoil=ph;
    }
    void calcFertiliser()
    {
        Scanner k = new Scanner(System.in);
        System.out.println("\n Enter the area of the field in acre");
        double fieldArea = k.nextDouble(),ratio = 6000*3.7;
        double water = fieldArea*ratio;
        double fer=0;
        if(text==1)
        fer=0.0025;
        if(text==2)
        fer=0.0030;
        if(text==3)
        fer=0.0035;
        if(phOfSoil<7)
        acidicFertiliser = true;
        else if(phOfSoil>7)
        basicFertiliser  = true;
        waterAmount = water;
        fertiliserAmount = fer*water;
        //System.out.println("Water = "+waterAmount+" liters");
       // System.out.println("Fertiliser = "+fertiliserAmount+" liters");
        
    }
    public static void main(String args[])
    {
         Main obj = new Main();
         obj.calcph();
         obj.calcFertiliser();
         obj.work();
         
    }
    void work()
    {
        Scanner k = new Scanner(System.in);
        while(true)
         {
         System.out.println("\n *--------------------------------------------------------------------------------------*");
         System.out.println(" Enter 1 if you want to see the soil report");
         System.out.println(" Enter 2 if you want to start the irrigation process according to the soil report");
         System.out.println(" Enter 3 to see the level of water remaining in the tubewell after performing irrigation");
         System.out.println(" Enter 4 to see the charge remaining in the solar panel system ");
         System.out.println(" Enter 5 to see the status of streetlights");
         System.out.println(" Enter 6 to end the program");
         int x = k.nextInt();
         
         if(x==1)
         print(1);
         else if(x==2)
         print(2);
         else if(x==3)
         print(3);
         else if(x==4)
         print(4);
         else if(x==5)
         print(5);
         else if(x==6)
         {System.out.println("\n PROGRAM END"); break;}
         
    }
    }
    void irrigation()
    {
        tubewellLevel -= waterAmount;
    }
    void tubewell()
    {
        System.out.println("\n Volume of water in the tubewell present right now = "+ tubewellLevel +" litres");
        if(tubewellLevel < 0.4 * maxTubewell)
        {
            System.out.println(" WATER LEVEL LOW!");
            System.out.println(" Water has started to fill in the tubewell...");
            tubewellLevel = maxTubewell;
            for(int i =1;i<=1000000000;i++){}
            System.out.println("Water has been refilled in the tubewell");
            System.out.println(" Volume of Water in tubewell = "+tubewellLevel);
        }
    } 
    void print(int x)
    {
        int done=0;
        if(x==1)
        {
            System.out.println("\n Soil Report-:");
            System.out.println("    pH level of the soil = "+phOfSoil);
            if(acidicFertiliser)
            System.out.println("    Acidic Fertiliser required");
            else if(basicFertiliser)
            System.out.println("    Basic Fertiliser required");
            else System.out.println("    No Fertiliser required");
            System.out.println("    Fertiliser amount required "+ fertiliserAmount +" liters");
            System.out.println("    Volume of water required "+ waterAmount +" liters");
            if(acidicFertiliser)
            System.out.println("    N = 30%     |     P = 10%     |     K = 10% \n           Remaining 50% = S,Fe,Mn");
            else if(basicFertiliser)
            System.out.println("    N = 20%     |     P = 20%     |     K = 20% \n           Remaining 40% = Ca,Mg,S");
        }
        else if(x==2)
        {
            System.out.println("\nIrrigation system-:");
            System.out.println(" Volume of water in tubewell before irrigation =  "+tubewellLevel);
            System.out.println(" Water required = "+ waterAmount + " & Fertiliser required = "+fertiliserAmount+"\n");
            
            while(done<=100)
            {
            for(double i =1;i<=400000000.0;i++){}
            System.out.println(" Irrigation in progress...."+ done +" % done");
            done = done + 25;
            }
            System.out.println(" Irrigation Completed...");
            irrigation();
            tubewell();   
            solarEnergy();
        }
        else if(x==3)
        {irrigation();
        tubewell();
            solarEnergy();
        }
        else if(x==4)
        System.out.println("\n Current Battery Level = "+ charge);
        else if(x==5)
        streetLights();
}
    void solarEnergy()
    {
        charge -= 25;
        if(charge<30)
        {
            System.out.println("    BATTERY LOW!");
            System.out.println("Charging has started");
            for(double i =1;i<=400000000.0;i++){}
            System.out.println("Fully Charged");
            charge=100;
        }
    }
    void streetLights()
    {
        boolean isDaytime = false;
        boolean isNighttime = false;
    
       // create a Date object to get the current time
      TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata")); // Set timezone to IST
      Calendar calendar = Calendar.getInstance(); // Get instance of calendar
      int h = calendar.get(Calendar.HOUR_OF_DAY); // Get current hour in 24-hour format
         if(h>=6 && h<=17)
         isDaytime=true;
         else
         isNighttime=true;
        if (isNighttime) {
        System.out.println("\n Lights have been turned ON");
        }
        else 
        if (isDaytime){
            System.out.println("\n Lights have been turned OFF and charging is ON");
        }
    }
}
