#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// creating global variables
int option_select; // used to select an option in our menus
int current_user; // stores array index for current user

struct user_acc // creating structure for user input
{
    int id;
    char name[50];
    int age;
    char address[100];
    char schedule[12];
    int package;
    char mob_no[11];
    char email[30];
    char username[20];
    char password[20];
    char diet[40];
    char disease[25];
    float weight;
    float height;
};
struct user_acc arr_users[100]; // creating a global array to store user data

// function prototypes -
void member_section();
void main_menu();
void info();
void user_sign_in();
void user_sign_up();
void user_homepage();
void acc_details();
void calorie();
int met();
void bmi();
void modify_info();
void equip_detials();
void user_info_display();
void trainer_details();
void modify();
void delete ();
void attendance();
void management_signin();
void management_menu();

int main()
{
    main_menu();
    return 0;
}

void main_menu() // Main Menu of our program
{
    printf("\n\n*** Welcome to IIIT VADODARA GYMKHANA ***\n\n");
back_flag:
    printf("Enter 1 to know more about IIIT Vadodara Gymkhana\nEnter 2 to open Management Section\nEnter 3 to open Members Section\nEnter 4 to Exit\n\n");
    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
        info();
        break;
    case 2:
        management_signin();
        break;
    case 3:
        member_section();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid Value Entered!\n\n");
        goto back_flag;
        break;
    }
}

void info() // info about gym
{
    printf("*******************************************************************************************************************\n");
    printf("*******************************************************************************************************************\n");
    printf("***                                                                                                             ***\n");
    printf("***                                             IIIT VADODARA GYMKHANA                                          ***\n");
    printf("***                                                                                                             ***\n");
    printf("*** 1.  Gymkhana is one the best self sufficient gym among all the local gyms in the community                  ***\n");
    printf("*** 2.  We are well eqipped with the necessary basic eqipments and with the advance body shaping eqipments also ***\n");
    printf("*** 3.  We have a seperate room for normal free workout activities                                              ***\n");
    printf("*** 4.  We have a work force of a dedicated team, consisting of 3 well trained trainers and the manager         ***\n");
    printf("*** 5.  We have a facility of steam bath which could be used on every saturday                                  ***\n");
    printf("*** 6.  Free yoga session is also available for members enrolling for 1 year                                    ***\n");
    printf("*** 7.  We also take care of cleanliness and hygiene of all the eqipments                                       ***\n");
    printf("*** 8.  We follow a strict set of safety measure to avoid COVID situation                                       ***\n");
    printf("*** 9.  We have flexible and affordable pakages for enrollment on the basis of the duration                     ***\n");
    printf("*** 10. Upon enrollment you will be appointed one permanent trainer for guidance                                ***\n");
    printf("*** 11. You will also be provided with the diet plan according to the workout that you choose                   ***\n");
    printf("***                                                                                                             ***\n");
    printf("*******************************************************************************************************************\n");
    printf("*******************************************************************************************************************\n");
    main_menu();
}

void member_section() // Members Section of our program
{
    printf("\nIf you're a past user enter 1 to Sign-In\nIf you're a new user enter 2 to Sign-Up\nEnter 3 to go back\n\n");
    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
        user_sign_in();
        break;
    case 2:
        user_sign_up();
        break;
    case 3:
        main_menu();
        break;
    default:
        printf("Invalid Value Entered!");
        member_section();
        break;
    }
}

void user_sign_up() // sign up menu
{
    printf("\nWelcome to Sign-up Menu\n\n");
    static int id = 1;
    int arr_element;

    for (int i = 0; i < 100; i++)
    {
        if (arr_users[i].id == 0)
        {
            arr_element = i;
            break;
        }
    }

    arr_users[arr_element].id = id;
    id++;

username_flag:
    printf("Enter desired Username : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].username);
    short int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(arr_users[i].username, arr_users[arr_element].username) == 0)
        {
            count++;
        }
    }
    if (count != 1)
    {
        printf("Username already in use, Try Again.\n\n");
        goto username_flag;
    }
    else
    {
        printf("Username Assigned Succesfully.\n\n");
    }

    printf("Enter Password : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].password);

    printf("Enter Name : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].name);

    printf("Enter Age : ");
    scanf(" %d", &arr_users[arr_element].age);

    printf("Enter Address : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].address);

    printf("Enter Mobile Number : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].mob_no);

    printf("Enter E-mail : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].email);

    printf("Enter Schedule : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].schedule);

    printf("Enter Height (in cm) : ");
    scanf(" %f", &arr_users[arr_element].height);

    printf("Enter Weight (in kg) : ");
    scanf(" %f", &arr_users[arr_element].weight);

    printf("\nEnter Basic Information about your Diet\n");
    scanf(" %[^\n]%*c", arr_users[arr_element].diet);

    printf("\nEnter Diseases (if any) : ");
    scanf(" %[^\n]%*c", arr_users[arr_element].disease);

    printf("\nUser Account Created Succesfully.");
    member_section();
}

void user_sign_in() // sign in menu
{
    char username_temp[20];
    char password_temp[20];
    int user_select;
    printf("Enter Username : ");
    scanf(" %[^\n]%*c", username_temp);
    printf("Enter Password : ");
    scanf(" %[^\n]%*c", password_temp);

    for (int i = 0; i < 100; i++)
    {
        if (strcmp(username_temp, arr_users[i].username) == 0)
        {
            user_select = i;
            break;
        }
    }

    if (strcmp(username_temp, arr_users[user_select].username) == 0 && strcmp(arr_users[user_select].password, password_temp) == 0)
    {
        current_user = user_select;
        user_homepage();
    }
    else
    {
    back_flag:
        printf("Incorrect Username or Password.\n\nTo retry, enter 1\nTo return to Members Section, enter 2 : ");
        scanf("%d", &option_select);
        if (option_select == 1)
        {
            user_sign_in();
        }
        else if (option_select == 2)
        {
            member_section();
        }
        else
        {
            printf("Invalid Value Entered!\n\n");
            goto back_flag;
        }
    }
}

void user_homepage() // a user's personalised homepage
{
    printf("\n\n*** Welcome to your Home Page ***\n\n");
    back_flag:
    printf(">For Account Details, enter 1\n>To know about equipments available at our gym, enter 2\n>To calculate calories burnt, enter 3\n>To calculate BMI, enter 4\n>To Sign Out, enter 5\n\n");
    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
        acc_details();
        break;
    case 2:
        equip_detials();
        break;
    case 3:
        calorie();
        break;
    case 4:
        bmi();
        break;
    case 5:
        member_section();
        break;
    default:
        printf("Invalid Value Entered!\n\n");
        goto back_flag;
        break;
    }
}

void calorie() // function for calorie calculations
{
    printf("\n***list of exercices :\n\n");
    printf("Ex.No\texercise name\n");
    printf("1.\tPush Ups\n2. \tPull Ups\n3. \tSit Ups\n4. \tJumping Jacks\n5. \tAbs Exercises\n");
    printf("6. \tCrunches\n7. \tLunges\n8. \tSquats\n9. \tRope Jumping\n10. \tCycling\n");
    printf("11. \tMountain Climbers\n12. \tWeight Lift\n13. \tBurpees\n14. \tRunning\n");
    printf("15. \tWalking\n");
    float x, time, MET = met(), weight_temp = arr_users[current_user].weight;
    printf("\nEnter the duration of the exercise performed in minutes : ");
    scanf("%f", &time);
    x = (time * MET * 3.5 * weight_temp) / 200.0;
    printf("\ncalories burned = %f\n\n", x);
    printf("**Daily calorie requirement for a male is 2,500 kcal and for a female is 2,000kcal ");
    printf("to meet the daily body's energy needs.\n**Don't decrease the calorie intake in order to ");
    printf("loose weight just avoid the excessive calorie intake.\n\n** Stay Healthy!! **\n\n");

    user_homepage();
}

int met() // this function gives met value to calorie calculation function
{
    float MET;
    int i;
    printf("\nPlease select the exercise number from the above list : ");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
    {
        MET = 8;
        break;
    }
    case 2:
    {
        MET = 8;
        break;
    }
    case 3:
    {
        MET = 8;
        break;
    }
    case 4:
    {
        MET = 7.7;
        break;
    }
    case 5:
    {
        MET = 7;
        break;
    }
    case 6:
    {
        MET = 5;
        break;
    }
    case 7:
    {
        MET = 4;
        break;
    }
    case 8:
    {
        MET = 8;
        break;
    }
    case 9:
    {
        MET = 10;
        break;
    }
    case 10:
    {
        MET = 7.5;
        break;
    }
    case 11:
    {
        MET = 8;
        break;
    }
    case 12:
    {
        MET = 6;
        break;
    }
    case 13:
    {
        MET = 8;
        break;
    }
    case 14:
    {
        MET = 9.8;
        break;
    }
    case 15:
    {
        MET = 3.1;
        break;
    }
    }
    return MET;
}

void bmi() // function for bmi calculation
{
    float c, iweight, weight = arr_users[current_user].weight, height = arr_users[current_user].height / 100.0;
    c = (weight) / (height * height);
    printf("your BMI is = %f kg/m2\n\n", c);

    if (c < 18.5)
        printf("You are underweight\n");
    else if (c >= 18.5 && c <= 24.9)
        printf("You are healthy\n");
    else if (c > 24.9 && c <= 30)
        printf("You are overweight\n");
    else if (c > 30)
        printf("You are obese\n");

    iweight = (2.2 * c) + (3.5 * c) * (height - 1.5);
    printf("\nYour ideal weight should be %f kg\n", iweight);
    user_homepage();
}

void equip_detials() // function to display equipments details
{
    printf("\nList Of Eqipments :\n\n");
    printf("Eq.No\tEquipment Name\n");
    printf("1.\tTreadmill\n2. \tMultigym\n3. \tElectric Gym Cycle\n4. \tDumbell Bench\n5. \tPush-up, Pull-up Bars\n");
    printf("6. \tWeight Bench\n7. \tGym Cable Machine\n8. \tBarbells\n9. \tGym Ball\n10. \tBattle Ropes\n");

    printf("\nPlease select the eqipment number from the above list : ");
    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
    {
        printf("\nAdvantages of Treadmill :-\n1) The treadmill is a relatively easy piece of exercise equipment to use.\n2) All aspects of the workout can be controlled by the user: speed, incline, warm up period, cool down period, \nand energy spend\n3)Running on a treadmill generally burns calories faster than most other forms of in-home exercise, such as biking.\n\nMajor Treadmill Workout Don'ts to Avoid :-\n1) Don't: Forget to warm up and cool down. One of the biggest mistakes that new gym members and treadmill beginners make is \nskipping over their warm up and cool down entirely. ...\n2) Don't: Overdo it. ... \n3) Don't: Tense up. ... \n4) Don't: Ignore incline. ... \n5) Don't: Lean on the railings. ... \n6) Don't: Have heavy feet. ... \n7) Don't: Be repetitive.\n");
        break;
    }
    case 2:
    {
        printf("\nAdvantages of Having a Multigym Equipment at Home :-\n1) Perform Diverse Workouts. A multigym will enable you to perform various types of exercises for every major muscle group.\n2) Build Muscle and Burn Fat. Multigyms are great when it comes to strength training.\n3) Ideal for Home Use.\n4) Safe and Easy to Use. \n5) No Need for Professional Help. \n6) Built to Last a Lifetime.\n\nPrecautions to be taken while exercising with Multi Station Gym :- \n1) Try not to practice on the off chance that you are not feeling great or have a fever. You ought to hold up a couple days after all side\neffects vanish before restarting the multi station gym exercise program, unless your specialist gives different headings.\n2) Check your pulse in the event that you build up a fast …\n");
        break;
    }
    case 3:
    {
        printf("\nAdvantages of electric gym cycle :-\n1) Increases metabolism and core muscle strength because it allows you to ride for longer\n2)Improves blood circulation, and facilitates stress release.\n3) Saves productive time/ Easy on the pocket.\n4) Exercise for longer durations (high endurance, medium intensity work-out).\n\nDisadvantages of gym cycle :-\n1)Miss Nature. When you choose indoor cycling over its outdoor counterpart, you're opting out of the refreshing experience a bike ride into\nnature can provide.\n2) Not Real-World Training.\n");
        break;
    }
    case 4:
    {
        printf("\nHealth benefits of dumbbells :-\n1) Boosting resting metabolic rate (burning calories)\n2)Protecting against injury.\n3) Increasing the strength of the bones, muscles, and connective tissue.\n4) You don't necessarily need a spotter. \n5) The One-Arm Dumbbell Bench will blast your core. \n6) You can isolate and identify weak spots in your lift.\n\nPrecautions for dumbbell bench :-\n1) Keep your spine flat throughout the exercise and avoid arching your low back.\n2) Press your head, shoulders, and buttocks into the bench the entire time.\n3) You can use a raised platform under your feet.\n4) Press your feet firmly into the floor or platform throughout the exercise.\n6) To target your triceps, draw your elbows in close to your sides.\n7) To target your pectorals, flare your elbows out away from your body.\n8) Keep your wrists neutral so they don’t bend in either direction.\n");
        break;
    }
    case 5:
    {
        printf("\nAdvantages of Push-up, Pull-up bars :-\n1) Traditional pushups are beneficial for building upper body strength. They work the triceps, pectoral muscles,\n and shoulders.\n2) Increase Functional Strength via Full Body Activation.\n3)Strengthen the back muscles\n4)You'll Have More Muscular Endurance. \n5) Your Grip Strength Will Be Insane.\n\nPrecautions for Push-up, Pull-up bars :-\n1) Don't be afraid to start on your knees. \n2) Do perform partial reps in a full push-up position.\n3) Actively press away from the ground with your hands.\n4) Change your hand placement to change the emphasis of the move.\n5) To protect your body from injury, use proper form — keeping your legs still and gripping the bar at or just beyond \nshoulder distance as you pull your elbows toward your body.\n");
        break;
    }
    case 6:
    {
        printf("\nAdvantages of weight bench :-\n1) Controlling mechanical overload and path of motion.\n2) Creating metabolic overload.\n3) Placing resistance specifically on the contractile element of muscle.\n4) Focus on developing definition in specific muscles.\n\nPrecautions for weight machine :-\n1)Don't hyperventilate (breathe in and out fast) or hold your breath when you lift heavy weights.\n2) Don't continue lifting if you feel pain. \n3) Don't lift weights if you are light-headed.\n4) Don't exercise any set of muscles more than three times a week.\n");
        break;
    }
    case 7:
    {
        printf("\nAdvantages of gym cable machines :-\n1) Cable machines provide constant tension while you lift and lower the weight. \n2)Since muscle growth and strength increases are directly based on how much tension is placed on the muscle during the exercise\n3)cable machines fatigue muscles faster and result in greater strength gains.\n4) As you become more proficient in the use of cable machines, you discover the multitude of exercises that can be done at a \nsingle Machine, allowing you to quickly switch between various exercises, as well as work upper and lower body simultaneously.\n\nPrecautions before using gym cable machines :-\n1)Give yourself enough room - The cable machine takes up a lot of floor space, and you need to be able to move freely while \ndoing the exercises.\n2) Ask for assistance - If you’re not sure what height to set the cables at, or how to do a move, always ask a certified \npersonal trainer for assistance. Performing an exercise at the wrong height not only decreases the effectiveness, but it also \nincreases your chance for injury.\n3) Check for damage -  Check the cables and attachments before you use them and alert a staff member if you see fraying or \nsplitting on the cables.\n");
        break;
    }
    case 8:
    {
        printf("\nAdvantages of barbells :- \n1) They save time. The Big Four barbell exercises (squat, bench press, overhead press, and deadlift) offer an overall workout \nbecause they each utilize multiple muscle groups. \n2) They improve athletic performance. \n3) They're affordable. \n4) They're versatile.\n\nPrecautions of barbells :-\n>> Don't hyperventilate (breathe in and out fast) or hold your breath when you lift heavy weights. You may faint and lose \ncontrol of the weights. Breathe out when you lift. Don't continue lifting if you feel pain.\n");
        break;
    }
    case 9:
    {
        printf("\nAdvantages of gym ball :-\n1) Body weight workouts are useful mentally and physically since you're basically working against your own body weight. \n2) Strengthens Your Core. \n3) Improve Your Flexibility.\n4) Improve Your Balance. \n5) Back and spine health. \n6) Cardio Burn. \n7) Aid in Sports Performance.\n\nPrecautions for gym Ball exercise :- \n1) Exercises should be done in a controlled manner and speed; starting slowly and building confidence.\n2) The constant use of muscle groups to maintain balance on an exercise ball may lead to quicker than expected fatigue, and \npatients may find that at least at first they need to do shorter exercise routines than expected.\n3) A physician should always be consulted about conditions that can be aggravated by this form of exercise before proceeding.\n");
        break;
    }
    case 10:
    {
        printf("\nAdvantages of battle ropes :-\n1) They blast fat.\n2) They sculpt muscles. \n3) They increase mobility. \n4) Likelihood of injuries is low. \n5) The benefits of rope training include increased power, strength, flexibility, and endurance. \n6) A few whips of these heavy ropes propel one's heart to its maximum rate.\n\nPrecautions for battle ropes :-\n1) Space and availability. Much like the battle ropes finding enough room and an actual sled can be a challenge - not all gyms carry such\nequipment. \n2) Another factor to carefully consider is using proper form and technique – injury is a concern for those with little to no experience.\n");
        break;
    }
    }

back_flag:
    printf("\nTo view information about our equipments enter 1, else to return to your Homepage enter 2 : ");
    scanf("%d", &option_select);
    if (option_select == 1)
    {
        equip_detials();
    }
    else if (option_select == 2)
    {
        user_homepage();
    }
    else
    {
        printf("Invalid Value Entered!\n\n");
        goto back_flag;
    }
}

void acc_details() // function to view account details of a user
{
    printf("\nAccount related details are - \n\n");
    printf("Member ID - %d\n", arr_users[current_user].id);
    printf("Username - %s\n", arr_users[current_user].username);
    printf("Password - %s\n", arr_users[current_user].password);
    printf("\nPersonal details are - \n\n");
    printf("Name - %s\n", arr_users[current_user].name);
    printf("Age - %d\n", arr_users[current_user].age);
    printf("Address - %s\n", arr_users[current_user].address);
    printf("Mobile Number - %s\n", arr_users[current_user].mob_no);
    printf("Email - %s\n", arr_users[current_user].email);
    printf("Schedule - %s\n", arr_users[current_user].schedule);

    if (arr_users[current_user].package == 0)
    {
        printf("Package (in months) - Not Added yet, please contact the Manager.\n");
    }
    else
    {
        printf("Package (in months) - %d\n", arr_users[current_user].package);
    }

    printf("Height - %f cm\n", arr_users[current_user].height);
    printf("Weight - %f kg\n", arr_users[current_user].weight);
    printf("Diet - %s\n", arr_users[current_user].diet);
    printf("Diseases - %s\n", arr_users[current_user].disease);

back_flag:
    printf("To modify, enter 1\nTo go back, enter 2\n");
    scanf("%d", &option_select);
    if (option_select == 1)
    {
        modify_info();
    }
    else if (option_select == 2)
    {
        user_homepage();
    }
    else
    {
        printf("Invalid Value Entered!\n\n");
        goto back_flag;
    }
}

void modify_info() // function to modify account details of a user
{
back_flag1:

    printf("Detail No.\tDetail\n1.\tUsername\n2. \tPassword\n3. \tName\n4. \tAge\n5. \tAddress\n");
    printf("6. \tMobile No.\n7. \tE-mail\n8. \tSchedule\n9. \tHeight\n10. \tWeight\n11. \tDiet\n12. \tDisease\n");
    printf("\nPlease select the Detail No. from the above list : ");
    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
    {
        printf("\nEnter new Username : ");
        scanf(" %[^\n]%*c", arr_users[current_user].username);
        break;
    }
    case 2:
    {
        printf("\nEnter new Password : ");
        scanf(" %[^\n]%*c", arr_users[current_user].password);
        break;
    }
    case 3:
    {
    back_flag2:
        printf("\nEnter new Name : ");
        scanf(" %[^\n]%*c", arr_users[current_user].name);
        if (strcmp(arr_users[current_user].name, "") == 0)
        {
            printf("Invalid!\nDo not leave Name as blank.\n");
            goto back_flag2;
        }
        break;
    }
    case 4:
    {
        printf("\nEnter new Age : ");
        scanf(" %d", &arr_users[current_user].age);
        break;
    }
    case 5:
    {
        printf("\nEnter new Address : ");
        scanf(" %[^\n]%*c", arr_users[current_user].address);
        break;
    }
    case 6:
    {
        printf("\nEnter new Mobile No. : ");
        scanf(" %[^\n]%*c", arr_users[current_user].mob_no);
        break;
    }
    case 7:
    {
        printf("\nEnter new E-mail : ");
        scanf(" %[^\n]%*c", arr_users[current_user].email);
        break;
    }
    case 8:
    {
        printf("\nEnter new Schedule : ");
        scanf(" %[^\n]%*c", arr_users[current_user].schedule);
        break;
    }
    case 9:
    {
        printf("\nEnter new Height : ");
        scanf(" %f", &arr_users[current_user].height);
        break;
    }
    case 10:
    {
        printf("\nEnter new Weight : ");
        scanf(" %f", &arr_users[current_user].weight);
        break;
    }
    case 11:
    {
        printf("\nEnter new Diet : ");
        scanf(" %[^\n]%*c", arr_users[current_user].diet);
        break;
    }
    case 12:
    {
        printf("\nEnter new Disease : ");
        scanf(" %[^\n]%*c", arr_users[current_user].disease);
        break;
    }
    default:
    {
        printf("Invalid Value Entered!\n\n");
        goto back_flag1;
    }
    }
    acc_details();
}

void management_signin() // Management section sign in, to be acccesed only by manager
{
    char username_input[50];
    char password_input[50];
    printf("\n\n****Welcome to Management Section****\n\n");
    printf("ONLY MANAGER CAN ACCESS THIS SECTION\n\n");

back_flag1:
    printf("To login enter 1\nTo go back to Main menu enter 2\n");
    scanf("%d", &option_select);

    if (option_select == 1)
    {
        printf("\nEnter username\n");
        scanf(" %[^\n]%*c", username_input);
        printf("\nEnter password \n");
        scanf(" %[^\n]%*c", password_input);
        if (strcmp(username_input, "manager@IIITV") == 0 && strcmp(password_input, "gymislife") == 0)
        {
            management_menu();
        }
        else
        {
            printf("\nInvalid password or username\n");
            goto back_flag1;
        }
    }

    else if (option_select == 2)
    {
        main_menu();
    }

    else
    {
        printf("\nInvalid entry\n");
        goto back_flag1;
    }
}

void management_menu() // Management menu
{

back_flag2:
    printf("\n\nFor user's information enter 1\nTo modify user's information enter 2\nTo delete users information enter 3\nFor Trainer's information enter 4\nFor trainer's attendance enter 5\nElse enter 6 to back to Main menu\n");

    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
        user_info_display();
        break;
    case 2:
        modify();
        break;
    case 3:
        delete();
        break;
    case 4:
        trainer_details();
        break;
    case 5:
        attendance();
        break;
    case 6:
        main_menu();
        break;
    default:
        printf("Invalid entry\n");
        goto back_flag2;
    }
}

void user_info_display() // function to display basic details of all users
{
    printf("\n\t\t******User's information********\n");
    for (int i = 0; i < 100; i++)
    {
        if (arr_users[i].id != 0)
        {
            printf("ID : %d\nName : %s\nSchedule : %s\nPackage : %d\n\n", arr_users[i].id, arr_users[i].name, arr_users[i].schedule, arr_users[i].package);
        }
    }
    management_menu();
}

void modify() // function to modify details of user
{
    int id_input;
    printf("\nEnter the id of the user to modify their details : \n");
    scanf("%d", &id_input);
    for (int i = 0; i < 100; i++)
    {
        if (id_input == arr_users[i].id)
        {
            current_user = i;
            break;
        }
    }

back_flag1:

    printf("\nDetail No.\tDetail\n1.\tName\n2.\tUsername (to be used for recovery purposes only)\n3.\tPassword (to be used for recovery purposes only)\n4.\tSchedule\n5.\tPackage(add / modify)\n");
    printf("\nPlease select the Detail No. from the above list : ");
    scanf("%d", &option_select);
    switch (option_select)
    {
    case 1:
        printf("Enter new Name\n");
        scanf(" %[^\n]%*c", arr_users[current_user].name);
        break;
    case 2:
    username_flag:
        printf("Enter new Username\n");
        scanf(" %[^\n]%*c", arr_users[current_user].username);

        short int count = 0;
        for (int i = 0; i < 100; i++)
        {
            if (strcmp(arr_users[i].username, arr_users[current_user].username) == 0)
            {
                count++;
            }
        }

        if (count != 1)
        {
            printf("Username already in use, Try Again.\n\n");
            goto username_flag;
        }

        break;
    case 3:
        printf("Enter new Password\n");
        scanf(" %[^\n]%*c", arr_users[current_user].password);
        break;
    case 4:
        printf("Enter new Schedule\n");
        scanf(" %[^\n]%*c", arr_users[current_user].schedule);
        break;
    case 5:
        printf("Enter new Package\n");
        scanf("%d", &arr_users[current_user].package);
        break;
    default:
        printf("Invalid entry\n");
        goto back_flag1;
    }

back_flag2:

    printf("\nTo Modify another detail of the same user enter 1\n\nTo Modify another details of another user enter 2\n\nTo go back to Management Section enter 3\n\n");
    scanf("%d", &option_select);

    if (option_select == 1)
    {
        goto back_flag1;
    }
    else if (option_select == 2)
    {
        modify();
    }
    else if (option_select == 3)
    {
        management_menu();
    }
    else
    {
        printf("Invalid entry\n");
        goto back_flag2;
    }
}

void delete () // function to delete basic data of user
{
    printf("\n\t\t******User's information********\n");
    for (int i = 0; i < 100; i++)
    {
        if (arr_users[i].id != 0)
        {
            printf("ID : %d\nName : %s\nSchedule : %s\nPackage : %d\n\n", arr_users[i].id, arr_users[i].name, arr_users[i].schedule, arr_users[i].package);
        }
    }
    int id_input;
    char confirm_option;
    back_flag1:
    printf("Enter the id of the user to delete their details, else enter 0 to back to go back to Management menu\n");
    scanf("%d", &id_input);
    if (id_input == 0)
    {
        management_menu();
    }
    for (int i = 0; i < 100; i++)
    {
        if (id_input == arr_users[i].id)
        {
            current_user = i;
            break;
        }
    }

back_flag2:

    printf("Enter 'y' to confirm, or 'n' to go back\n");
    scanf(" %c", &confirm_option);
    if (confirm_option == 'y' || confirm_option == 'Y')
    {
        arr_users[current_user].age = 0;
        strcpy(arr_users[current_user].schedule, "");
        arr_users[current_user].package = 0;
        strcpy(arr_users[current_user].username, "");
        strcpy(arr_users[current_user].password, "");
        strcpy(arr_users[current_user].diet, "");
        arr_users[current_user].weight = 0.0;
        arr_users[current_user].height = 0.0;
    }
    else if (confirm_option == 'n' || confirm_option == 'N')
    {
        goto back_flag1;
    }
    else
    {
        printf("Invalid Value Entered!\n\n");
        goto back_flag2;
    }

    management_menu();
}

void trainer_details() // function to display trainer details of currently working trainers
{
    struct trainer_info
    {
        char name[50];
        char date_of_joining[10];
        int age;
    } trainer[5] = {{"Ravi", "12Dec2018", 27}, {"Madhur", "17Aug2015", 29}, {"Kunal", "23sep2016", 28}, {"Lakshay", "7Jan2014", 28}, {"Sai", "30Nov2017", 27}};

    printf("Name\t\tDate of Joining\t\tAge\n");
    for (int j = 0; j < 5; j++)
    {
        printf("%s\t\t%s\t\t%d\n", trainer[j].name, trainer[j].date_of_joining, trainer[j].age);
    }
    management_menu();
}

void attendance() // function for marking attendance of trainers
{
    char Ravi[7] = {'p', 'a', 'p', 'p', 'a', 'p'};
    char Lakshay[7] = {'p', 'p', 'p', 'p', 'p', 'p'};
    char Sai[7] = {'p', 'a', 'p', 'p', 'p', 'p'};
    char Madhur[7] = {'p', 'a', 'p', 'p', 'a', 'p'};
    char Kunal[7] = {'p', 'p', 'p', 'p', 'a', 'p'};

    printf("\nEnter 'p' if present else 'a' for absent\n");
    printf("Ravi : ");
    scanf(" %c", &Ravi[6]);
    printf("Lakshay : ");
    scanf(" %c", &Lakshay[6]);
    printf("Sai : ");
    scanf(" %c", &Sai[6]);
    printf("Madhur : ");
    scanf(" %c", &Madhur[6]);
    printf("Kunal : ");
    scanf(" %c", &Kunal[6]);
    management_menu();
}
