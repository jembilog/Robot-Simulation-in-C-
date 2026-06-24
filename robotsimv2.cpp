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
        if(y < 0 || y >= static_cast<int>(map.size()))
            return true;

        if(x < 0 || x >= static_cast<int>(map[y].size()))
            return true;

        return map[y][x] == 'X';
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
            cout << "Obstacle detected! Cannot move forward.\n";
            return;
        }

        x = nextX;
        y = nextY;

        cout << "Robot moved forward.\n";
    }

    void moveBackward(Environment &environment)
    {
        int nextX = x;
        int nextY = y;

        if(direction == "North")
            nextY++;
        else if(direction == "South")
            nextY--;
        else if(direction == "East")
            nextX--;
        else if(direction == "West")
            nextX++;

        if(environment.isObstacle(nextX,nextY))
        {
            cout << "Obstacle detected! Cannot move backward.\n";
            return;
        }

        x = nextX;
        y = nextY;

        cout << "Robot moved backward.\n";
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

    void displayStatus() const
    {
        cout << "\n===== ROBOT STATUS =====\n";
        cout << "Position: (" << x << ", " << y << ")\n";
        cout << "Direction: " << direction << endl;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
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
        world.display(robot.getX(), robot.getY());

        cout << "\n===== ROBOT CONTROL =====\n";
        cout << "1. Move Forward\n";
        cout << "2. Move Backward\n";
        cout << "3. Turn Left\n";
        cout << "4. Turn Right\n";
        cout << "5. Robot Status\n";
        cout << "0. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                robot.moveForward(world);
                break;

            case 2:
                robot.moveBackward(world);
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

            case 0:
                cout << "Robot shutdown.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 0);

    return 0;
}