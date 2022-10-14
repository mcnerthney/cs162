#include <iostream>
using namespace std;
// Nolan McNerthney, CS 162, Project #1 


int main()
{
	//To see if the program should terminate	
	char run_program{'Y'};  


	//Welcome the user and explain how the program works
        cout << "Welcome to the planning app!" << endl
	<<	"This app will determine if your daily workload is right for you." << endl
	<<	"This is done by asking how many hours you want to work, how many projects you want to work on, and how many hours a day you want to work on each project." << endl
	<<	"Then the app will calculate if the total hours working on projects is in an appropriate range. Let's begin!" << endl; 

	//Run the program
	while (toupper(run_program) == 'Y'){                   

		//Define variables
		char project_number_comf{'N'}; //Confirm the number of projects
		char get_total_hours{1};       //To loop getting total hours till an appropriate value is inputted
		char get_project_number{1};    //To loop getting 	
		int project_number{0};         //Keeps track of the amount of projects  
        	int count{1};                  //A counter that will go up as users enter info on each project
       		float project_hours{0};          //The amount of hours for one project
		float total_hours{0};            //The amount of hours for all project                	
		float  hours_day{0};              //The amount of hours the user wants to work in a day


		//Get total hours per day
		while(get_total_hours == 1){

			cout << "How many hours do you want to work in a day? (Can't exceed 8hrs): "	<< endl;
			cin >> hours_day;
			cout << "You want to spend " << hours_day << "hrs working on projects." << endl;
		
			//Error check for hours
			if(hours_day < 0 || hours_day > 8){
				cout << "Uh-oh, you entered an unexpected value. Please try again." << endl;
				get_total_hours = 1; 

			}

			//If no errors break loop
			else{
				get_total_hours = 0;
			}
		}
	
		//Get number of projects
		while (get_project_number == 1){
		
			cout << "How many projects do you want to work on?" << endl;
			cin >> project_number;

			//Error check number of projects
			if(project_number < 0){
				cout << "Uh-oh, you entered an unexpected value. Please try again." << endl; 
				get_project_number = 1; 
			}

			//If no errors break loop
			else{
		
				cout << "You want to work on " << project_number << " projects." << endl; 	
				get_project_number = 0; 
			}

		}
	
		//Get hours per project
		while (count <= project_number){
			
			cout << "How many hours per day do you want to work on project #" << count << ":";
			cin >> project_hours;
	
			if(project_hours < 0 || project_hours > 8){
				cout << "Uh-oh, you entered an unexpected value. Please try again." << endl; 
				count = 1;	
				total_hours = 0; 	
			}
			else{

				total_hours += project_hours;
				count += 1;
			}	
		}
		
		//Calculate results
		
		//First let the user know how many hours they are to work
		cout << "You are scheduled to work " << total_hours << "hrs per day" << endl;

		//Next determine if the hours are in the appropriate range
		
		//The hours are less than half of what the user wants to work
		if(total_hours < 0.5*hours_day){
			cout << "This is less than half the hours you want to work per day." << endl
			<<	"Do you want to add more projects or increase the hours allocated for certain projects? Y or N" << endl;
			cin >> run_program;
		}
		
		//The hours are more than the user wants to work
		if(total_hours > hours_day){
			cout << "This is more than the hours you want to work in a day." << endl
			<<	"Do you want to work on less projects or decrease the hours allocated for certain projects? Y or N" << endl;
			cin >> run_program;
		}
		
		//The hours are in the appropriate range
		if(0.5*hours_day <= total_hours && total_hours  <= hours_day){
			cout << "This looks like a good schedule!" << endl
			<<	"Do you want to run the program again? Y or N" << endl;
			cin >> run_program;
		}
	
	}
	
	//Termination message
	cout << "Goodbye! :)" << endl;
  
	return 0;
    }
