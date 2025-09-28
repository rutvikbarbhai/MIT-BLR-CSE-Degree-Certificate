package com.course.structure;
public class BuildingMain{
	public int squareFootage;
	public int stories;
	public BuildingMain(int sF, int st){
		squareFootage = sF;
		stories = st;
	}
	public void display(){
		System.out.println("\nThe Square footage is: " + squareFootage + "\nThe number of stories is: " + stories); 
	}
}