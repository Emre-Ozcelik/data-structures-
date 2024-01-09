package cp213;

/**
 * Inherited class in simple example of inheritance / polymorphism.
 *
 * @author Emre Ozelik 
 * @version 2022-02-25
 */
public class CAS extends Professor {
	private String term = null;
	public CAS(String lastName, String firstName, String department, final String term) {
		super(lastName, firstName, department);
		this.term = term;
		// TODO Auto-generated constructor stub
	}
	public String getTerm() {
		return this.term;
	}
	@Override
	public String toString() {
		return(super.toString() + "\nTerm: " + this.term);
	}

}
