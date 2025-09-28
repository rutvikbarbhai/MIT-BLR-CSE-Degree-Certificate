package com.course.structure;
import com.course.structure.*;
public class School extends BuildingMain{
	public int noOfClassrooms;
	public String gradeLevel;
	public School(int sF, int st, int noC, String gL){
		super(sF,st);
		noOfClassrooms = noC;
		gradeLevel = gL;
	}
	public void display(){
		super.display();
		System.out.println("The number of classrooms is: " + noOfClassrooms + "\nThe grade level is: " + gradeLevel); 
	}
}
