import com.course.structure.House;
import com.course.structure.BuildingMain;
import com.course.structure.School;

public class Houses{
	public static void main(String[] args){
		House h1 = new House(500, 4, 4, 3);
		h1.display();
		BuildingMain b1 = new BuildingMain(300,3);
		b1.display();
		School s1 = new School(8000, 5, 23, "Secondary");
		s1.display();
	}
}