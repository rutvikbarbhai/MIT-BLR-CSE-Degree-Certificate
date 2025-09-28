package com.course.structure;
import com.course.structure.*;
public class House extends BuildingMain{
	public int noOfBeds;
	public int noOfBathrooms;
	public House(int sF, int st, int noBe, int noBa){
		super(sF, st);
		noOfBeds = noBe;
		noOfBathrooms = noBa;
	}
	public void display(){
		super.display();
		System.out.println("The number of beds is: " + noOfBeds + "\nThe number of bathrooms is: " + noOfBathrooms); 
	}
}
