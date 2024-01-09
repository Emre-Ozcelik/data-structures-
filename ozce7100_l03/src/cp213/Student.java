package cp213;

import java.time.LocalDate;

/**
 * Student class definition.
 *
 * @author Ilyas Emre Ozcelik
 * @version 2022-01-17
 */
public class Student implements Comparable<Student> {

    // Attributes
    private LocalDate birthDate = null;
    private String forename = "";
    private int id = 0;
    private String surname = "";

    /**
     * Instantiates a Student object.
     *
     * @param id        student ID number
     * @param surname   student surname
     * @param forename  name of forename
     * @param birthDate birthDate in 'YYYY-MM-DD' format
     */
    public Student(int tempID, String tempSurname, String tempForename, LocalDate tempBirthDate) {
    	
    	id = tempID;
    	surname = tempSurname;
    	forename = tempForename;
    	birthDate = tempBirthDate;
    	
	return;
    }

    /*
     * (non-Javadoc)
     *
     * @see java.lang.Object#toString() Creates a formatted string of student data.
     */
    @Override
    public String toString() {
	String string = "";

	string = ("Name:      " + surname + ", " + forename + "\nID:        " + id + "\nBirthdate: " + birthDate);


	return string;
    }

    /*
     * (non-Javadoc)
     *
     * @see java.lang.Comparable#compareTo(java.lang.Object)
     */
    @Override
    public int compareTo(final Student target) {
	int result = 0;

	// Compare surnames
	if(this.surname.equals(target.surname)) {
		// Equal surnames, compare forenames
		if(this.forename.equals(target.forename)) {
			// Equal forenames, compare ID
			// Turn IDs into strings
			String id1 = Integer.toString(this.id);
			String id2 = Integer.toString(target.id);
			// Compare IDs
			for(int i = 0; i < id1.length(); i++) {
				if(Integer.parseInt(id1) < Integer.parseInt(id2)) {
					result = -1;
					break;
				}else if(Integer.parseInt(id1) > Integer.parseInt(id2)){
					result = 1;
					break;
				}	
			}
		}else {
			// Forenames are NOT equal
			// Iterates through the smaller string
			for(int i = 0; i < Math.min(this.forename.length(), target.forename.length()); i++) {
				// Get characters at index j
				char for1 = this.forename.charAt(i);
				char for2 = target.forename.charAt(i);
				// Compare
				if((int)(for1) < (int)(for2)) {
					result = -1;
				}else if((int)(for1) > (int)(for2)) {
					result = 1;
				}
			}
		}	
	}else {
		// Surnames are NOT equal
		//Iterate through the smaller string
		for(int i = 0; i < Math.min(this.surname.length(), target.surname.length()); i++) {
			// Get characters at index j
			char for1 = this.surname.charAt(i);
			char for2 = target.surname.charAt(i);
			// Compare
			if((int)(for1) < (int)(for2)) {
				result = -1;
			}else if((int)(for1) > (int)(for2)) {
				result = 1;
			}
		}
	}

	return result;
    }


    // getters and setters defined here
    public void setForename(String newForename) {
    	this.forename = newForename;
    }
    public String getForename() {
    	return this.forename;
    }
    
    public void setSurname(String newSurname) {
    	this.surname = newSurname;
    }
    public String getSurname() {
    	return this.surname;
    }
    
    public void setId(int newId) {
    	this.id = newId;
    }
    public Integer getId() {
    	return this.id;
    }
    
    public void setBirthDate(LocalDate newBirthDate) {
    	this.birthDate = newBirthDate;
    }
    public LocalDate getBirthDate() {
    	return this.birthDate;
    }
    

}
