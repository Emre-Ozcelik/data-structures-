package cp213;

/**
 * Inherited class in simple example of inheritance / polymorphism.
 *
 * @author Emre Ozcelik
 * @version 2022-02-25
 */
public class IA extends Student {
	private String course = null;
	public IA(String lastName, String firstName, String id, final String course) {
		super(lastName, firstName, id);
		this.course = course;
		// TODO Auto-generated constructor stub
	}
	public String getCourse() {
		return this.course;
	}
	@Override
	public String toString() {
		return(super.toString() + "\nCourse: " + this.course);
	}
}
