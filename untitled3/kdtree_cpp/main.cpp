#include <iostream>

#include <cmath>

using namespace std;

struct Point

{

    int x;

    int y;

    Point(int _x, int _y)

    {

        x = _x;

        y = _y;

    }

    Point()

    {

        x = 0;

        y = 0;

    }

};

struct Node

{

    Point pos;

    int data;

    Node(Point _pos, int _data)

    {

        pos = _pos;

        data = _data;

    }

    Node()

    {

        data = 0;

    }

};

class Quad

{

    Point topLeft;

    Point botRight;

    Node *n;

    Quad *topLeftTree;

    Quad *topRightTree;

    Quad *botLeftTree;

    Quad *botRightTree;

public:

    Quad()

    {

        topLeft = Point(0, 0);

        botRight = Point(0, 0);

        n = NULL;

        topLeftTree = NULL;

        topRightTree = NULL;

        botLeftTree = NULL;

        botRightTree = NULL;

    }

    Quad(Point topL, Point botR)

    {

        n = NULL;

        topLeftTree = NULL;

        topRightTree = NULL;

        botLeftTree = NULL;

        botRightTree = NULL;

        topLeft = topL;

        botRight = botR;

    }

    void insert(Node*);

    Node* search(Point);

    bool inBoundary(Point);

};

void Quad::insert(Node *node)

{

    if (node == NULL)

        return;

    if (!inBoundary(node->pos))

        return;

    if (abs(topLeft.x - botRight.x) <= 1 &&

        abs(topLeft.y - botRight.y) <= 1)

    {

        if (n == NULL)

            n = node;

        return;

    }

    if ((topLeft.x + botRight.x) / 2 >= node->pos.x)

    {

        // Indicates topLeftTree

        if ((topLeft.y + botRight.y) / 2 >= node->pos.y)

        {

            if (topLeftTree == NULL)

                topLeftTree = new Quad(

                        Point(topLeft.x, topLeft.y),

                        Point((topLeft.x + botRight.x) / 2,

                              (topLeft.y + botRight.y) / 2));

            topLeftTree->insert(node);

        }

            // Indicates botLeftTree

        else

        {

            if (botLeftTree == NULL)

                botLeftTree = new Quad(

                        Point(topLeft.x,

                              (topLeft.y + botRight.y) / 2),

                        Point((topLeft.x + botRight.x) / 2,

                              botRight.y));

            botLeftTree->insert(node);

        }

    }

    else

    {

        // Indicates topRightTree

        if ((topLeft.y + botRight.y) / 2 >= node->pos.y)

        {

            if (topRightTree == NULL)

                topRightTree = new Quad(

                        Point((topLeft.x + botRight.x) / 2,

                              topLeft.y),

                        Point(botRight.x,

                              (topLeft.y + botRight.y) / 2));

            topRightTree->insert(node);

        }

            // Indicates botRightTree

        else

        {

            if (botRightTree == NULL)

                botRightTree = new Quad(

                        Point((topLeft.x + botRight.x) / 2,

                              (topLeft.y + botRight.y) / 2),

                        Point(botRight.x, botRight.y));

            botRightTree->insert(node);

        }

    }

}

// Find a node in a quadtree

Node* Quad::search(Point p)

{

    // Current quad cannot contain it

    if (!inBoundary(p))

        return NULL;

    if (n != NULL)

        return n;

    if ((topLeft.x + botRight.x) / 2 >= p.x)

    {

        // Indicates topLeftTree

        if ((topLeft.y + botRight.y) / 2 >= p.y)

        {

            if (topLeftTree == NULL)

                return NULL;

            return topLeftTree->search(p);

        }

            // Indicates botLeftTree

        else

        {

            if (botLeftTree == NULL)

                return NULL;

            return botLeftTree->search(p);

        }

    }

    else

    {

        // Indicates topRightTree

        if ((topLeft.y + botRight.y) / 2 >= p.y)

        {

            if (topRightTree == NULL)

                return NULL;

            return topRightTree->search(p);

        }

            // Indicates botRightTree

        else

        {

            if (botRightTree == NULL)

                return NULL;

            return botRightTree->search(p);

        }

    }

};

// Check if current quadtree contains the point

bool Quad::inBoundary(Point p)

{

    return (p.x >= topLeft.x &&

            p.x <= botRight.x &&

            p.y >= topLeft.y &&

            p.y <= botRight.y);

} main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
