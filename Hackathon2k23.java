//Made by Ishan,gaurav,himanshu at 29/04/2023

import java.util.*;
class Main
{
    int text,colour;
    double phOfSoil,waterAmount,fertiliserAmount,tubewellLevel=10000000,maxTubewell = 10000000 ;
    boolean acidicFertiliser=false, basicFertiliser=false;
    void calcph()
    {
        Scanner k = new Scanner(System.in);
        double ph=-1;
        System.out.println("To know about the Soil Texture, please :");
        System.out.println("Enter 1 for Sandy Soil");
        System.out.println("Enter 2 for Clay Soil");
        System.out.println("Enter 3 for Loam  Soil");
        int a = k.nextInt();
        System.out.println("To know about the colour of the soil, please :");
        System.out.println("Enter 1 for Black Soil");
        System.out.println("Enter 2 for Red Soil");
        System.out.println("Enter 3 for Yellow Soil");
        int b = k.nextInt();
        
        text =a; colour=b;
        if(a==1 && b==1)
        ph=7;
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
        k.close();
    }
    void calcFertiliser()
    {
        Scanner k = new Scanner(System.in);
        System.out.println("Enter the area of the field in acre");
        double fieldArea = k.nextInt(),ratio = 6000*3.7;
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
        System.out.println("Water = "+waterAmount+" liters");
       // System.out.println("Fertiliser = "+fertiliserAmount+" liters");
        k.close();
    }
    public static void main(String args[])
    {
         Scanner k = new Scanner(System.in);
         Main obj = new Main();
         obj.calcph();
         obj.calcFertiliser();
         while(true)
         {
         System.out.println("Enter 1 if you want to see the soil report");
         System.out.println("Enter 2 if you want to start the irrigation process according to the soil report");
         System.out.println("Enter 3 to see the level of water remaining in the tubewell after performing irrigation");
         System.out.println("Enter 4 to see the charge remaining in the solar panel system after tubewell is filled by underground");
         System.out.println("Enter 5 to exit the program");
         int x = k.nextInt();
         
         if(x==1)
         obj.print(1);
         else if(x==2)
         obj.print(2);
         else if(x==3)
         obj.print(3);
         else if(x==4)
         obj.print(4);
         else if(x==5)
         {System.out.println("PROGRAM END"); break;}
         
         k.close();
    }
    }
    void irrigation()
    {
        tubewellLevel -= waterAmount;
    }
    void tubewell()
    {
        System.out.println("Volume of water in the tubewell = "+ tubewellLevel);
        if(tubewellLevel < 0.4 * maxTubewell)
        {
            System.out.println("WATER LEVEL LOW");
            System.out.println("Water has started to fill in the tubewell");
            tubewellLevel = maxTubewell;
            for(int i =1;i<=1000000000;i++){}
            System.out.println("Water filled in tubewell");
            System.out.println("Volume of Water in tubewell "+tubewellLevel);
        }
    } 
    void print(int x)
    {
        int done=0;
        if(x==1)
        {
            System.out.println("pH level of the soil = "+phOfSoil);
            if(acidicFertiliser)
            System.out.println("Acidic Fertiliser required");
            else if(basicFertiliser)
            System.out.println("Basic Fertiliser required");
            else System.out.println("No Fertiliser required");
            System.out.println("Fertiliser amount required "+ fertiliserAmount +" liters");
            System.out.println("Volume of water required "+ waterAmount +" liters");
            if(acidicFertiliser)
            System.out.println("The fertilizer contains 30% nitrogen, 10% phosphorus, and 10% potassium. The remaining 50% of the fertilizer is composed of secondary and micronutrients, such as sulfur, iron, and manganese, which can help address any nutrient deficiencies in the soil.");
            else if(basicFertiliser)
            System.out.println("The fertilizer contains 20% nitrogen, 20% phosphorus, and 20% potassium. The remaining 40% of the fertilizer is composed of secondary and micronutrients, such as calcium, magnesium, and sulfur, which can help address any nutrient deficiencies in the soil");
        }
        else if(x==2)
        {
            System.out.println("Volume of water remaining in tubewell =  "+tubewellLevel);
            System.out.println("Water required = "+ waterAmount + " Fertiliser required = "+fertiliserAmount);
            
            while(done<=100)
            {
            for(double i =1;i<=400000000.0;i++){}
            System.out.println("Irrigation in progress...."+ done +" % done");
            done = done + 25;
            }
            System.out.println("Irrigation Completed");
            irrigation();
            tubewell();   
        }
        else if(x==3)
        {irrigation();
        tubewell();}
}
}
