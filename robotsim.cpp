#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class UltrasonicSensor//sensor added
{
  public:
    bool obstacleDetected()
    {
        return rand() % 4 == 0;// 25% obstacle
    }  
};

class Robot 
{
    private:
        int x;
        int y;
        string direction;
        int battery;
        UltrasonicSensor sensor;
    public:
        Robot(){
            x = 0;
            y = 0;
            direction = "North";
            battery = 100;
        }

        void moveForward()
        {
            if(battery <= 0)
            {
                cout << "Battery empty. Cannot move.\n";
                return;
            }

            if(sensor.obstacleDetected())
            {
                cout << "Obstacle Detected\n";
                cout << "Cannot move forward\n";
                return;
            }

            if(direction == "North")
                y++;
            else if(direction == "South")
                y--;
            else if(direction == "East")
                x++;
            else if(direction == "West")
                x--;

            battery -= 5;
            cout << "Robot moved forward!\n";
        }

        void moveBackward()
        {
            if(battery <= 0)
            {
                cout << "Battery empty. Cannot move.\n";
                return;
            }

            if(direction == "North")
                y--;
            else if(direction == "South")
                y++;
            else if(direction == "East")
                x--;
            else if(direction == "West")
                x++;

            battery -= 5;
            cout << "Robot moved backward!\n";
        }

        void turnLeft()
        {
            if(direction == "North")
                direction = "West";
            else if(direction == "West")
                direction = "South";
            else if(direction == "South")
                direction = "East";
            else if(direction == "East")
                direction = "North";
            
            cout<< "Turned left\n";
        }

        void turnRight()
        {
            if(direction == "North")
                direction = "East";
            else if(direction == "East")
                direction = "South";
            else if(direction == "South")
                direction = "West";
            else if(direction == "West")
                direction = "North";
            
            cout << "Turned right\n";
        }

        void scan()
        {
            if(sensor.obstacleDetected())
            {
                cout << "Obstacle detected ahead!\n";
            }
            else
            {
                cout << "Path Clear\n";
            }
        }

        void displayStatus()
        {
            cout<< "\n===== ROBOT STATUS =====\n";

            cout << "Position: ("
                 << x << ",  "
                 << y << ")\n";
            
            cout << "Direction: "
                 << direction <<endl;

            cout << "Battery: "
                 << battery
                 << "%\n";
        }

        void recharge()
        {
            int choice;
            cout << "Battery: "
                 << battery
                 << "%\n";
            cout << "Charge the battery? (1/0): ";
            cin >> choice;

            if(choice == 1)
            {
                cout << "Battery charged to 100%\n";
                battery = 100;
                cout << "Battery: "
                    << battery
                    << "%\n";

            }
            if(!choice)
            {
                cout<<"Battery not charged, exiting...\n";
            }
        }
};

int main()
{
    srand(time(NULL));
    Robot robot;

    int choice;
    
    do
    {
        cout<< "\n====== ROBOT CONTROL =====\n";

        cout << "1. Move Forward\n";
        cout << "2. Move Backward\n";
        cout << "3. Turn Left\n";
        cout << "4. Turn Right\n";
        cout << "5. Display Status\n";
        cout << "6. Recharge\n";
        cout << "7. Scan Area\n";
        cout << "0. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            robot.moveForward();
            break;
        case 2:
            robot.moveBackward();
            break;
        case 3:
            robot.turnLeft();
            break;
        case 4:
            robot.turnRight();
            break;
        case 5: 
            robot.displayStatus();
            break;
        case 6:
            robot.recharge();
            break;
        case 7: 
            robot.scan();
            break;
        case 0: 
            cout << "Shutdown robot...\n";
            break;
        default:
            break;
        }   
    } while (choice != 0);
    
}
