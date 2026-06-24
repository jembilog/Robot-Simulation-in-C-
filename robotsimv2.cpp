#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Environment {

private:
    vector<string> map;
public:

    Environment()
    {
        map = {
            "..........",
            "...X......",
            "..........",
            ".....X....",
            "..........",
            ".........."
        };
    }
    bool isObstacle(int x, int y)
    {
        if(y < 0 || y >= map.size())
            return true;
        if(x < 0 || x >= map[y].size())
            return true;
        if(map[y][x] == 'X')
            return true;
        return false;
    }
    void display(int robotX, int robotY)
    {

        cout << "\n===== WORLD MAP =====\n";
        for(int y = 0; y < map.size(); y++)
        {
            for(int x = 0; x < map[y].size(); x++)
            {
                if(x == robotX && y == robotY)
                    cout << "R";
                else
                    cout << map[y][x];
            }
            cout << endl;
        }
    }

};
class Robot {

private:
    int x;
    int y;
    string direction;
public:
    Robot()
    {
        x = 0;
        y = 0;
        direction = "East";
    }
    void moveForward(Environment &environment)
    {
        int nextX = x;
        int nextY = y;
        if(direction == "North")
            nextY--;
        else if(direction == "South")
            nextY++;
        else if(direction == "East")
            nextX++;
        else if(direction == "West")
            nextX--;
        if(environment.isObstacle(nextX,nextY))
        {
            cout << "Obstacle detected! Cannot move.\n";
            return;
        }
        x = nextX;
        y = nextY;
        cout << "Robot moved.\n";

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
        cout << "Turned left.\n";

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

        cout << "Turned right.\n";
    }
    void displayStatus()
    {
        cout << "\n===== ROBOT STATUS =====\n";
        cout << "Position: ("
             << x
             << ", "
             << y
             << ")\n";
        cout << "Direction: "
             << direction
             << endl;

    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

};
int main()
{
    Environment world;
    Robot robot;
    int choice;
    do
    {
        world.display(
            robot.getX(),
            robot.getY()
        );
        cout << "\n===== ROBOT CONTROL =====\n";
        cout << "1. Move Forward\n";
        cout << "2. Turn Left\n";
        cout << "3. Turn Right\n";
        cout << "4. Robot Status\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                robot.moveForward(world);
                break;
            case 2:
                robot.turnLeft();
                break;
            case 3:
                robot.turnRight();
                break;
            case 4:

                robot.displayStatus();
                break;
            case 0:
                cout << "Robot shutdown.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }while(choice != 0);

    return 0;
}