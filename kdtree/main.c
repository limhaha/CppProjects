#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    int y;
    struct node *next;
};

struct node *head = 0;

struct kdtree_node *kd_root = 0;

struct kdtree_node
{
    struct node *data;
    struct kdtree_node *left;
    struct kdtree_node *right;
};

void insert(int _x, int _y)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->x = _x;
    new_node->y = _y;
    new_node->next = 0;

    if (head == 0)
    {
        head = new_node;
        return;
    }
    else
    {
        struct node *temp = head;
        while (1)
        {
            if (temp->next == 0)  // end of the node
            {
                temp->next = new_node;  // insert at the end
                return;
            }
            else // if not end of the node
            {
                // move to next node
                temp = temp->next;
            }
        }
    }
}

// Count node in List
int node_num(struct node *_head)
{
    int cnt = 0;
    struct node *temp = _head;

    while (1)
    {
        if (temp == 0)
        {
            return cnt;
        }
        else
        {
            cnt++;
            temp = temp->next;
        }
    }
}

//bubble sort
void sorting(struct node **_array, int _byX, int _size)
{
    int i = 0;
    int j = 0;

    for (j = 0; j < _size; j++)
    {
        for (i = 0; i < _size - 1 - j; i++)
        {
            if (_byX == 1)
            {
                if (_array[i]->x > _array[i + 1]->x)
                {
                    struct node *temp = _array[i];
                    _array[i] = _array[i + 1];
                    _array[i + 1] = temp;
                }
            }
            else
            {
                if (_array[i]->y > _array[i + 1]->y)
                {
                    struct node *temp = _array[i];
                    _array[i] = _array[i + 1];
                    _array[i + 1] = temp;
                }
            }
        }
    }
}

struct node *remake_node(struct node **_array, int from, int to)
{
    if (from > to)
    {
        return 0;
    }
    struct node *cur = _array[from];
    cur->next = 0;
    struct node *temp = cur;
    for (int i = from + 1; i <= to; i++)
    {
        temp->next = _array[i];
        temp->next->next = 0;
        temp = temp->next;
    }
    return cur;
}

// 2-dimension kd tree
struct kdtree_node *make_tree(struct node *sll,
                                 int _depth,
                                 int _dimension)
{
    if (sll == 0)
    {
        return 0;
    }

    int numSLLNodes = node_num(sll);

    struct node **nodeAddrArray = (struct node **)malloc(sizeof(struct node *)*numSLLNodes);

    int i;
    struct node *temp = sll;
    for (i = 0; i < numSLLNodes; i++)
    {
        nodeAddrArray[i] = temp;
        temp = temp->next;
    }

    int axis = _depth % _dimension;

    sorting(nodeAddrArray, !axis, numSLLNodes);

    int _median = numSLLNodes / 2;

    struct kdtree_node *cur = (struct kdtree_node *)malloc(sizeof(struct kdtree_node));
    cur->data = nodeAddrArray[_median];
    cur->left = make_tree(remake_node(nodeAddrArray, 0, _median - 1), _depth + 1, 2);
    cur->right = make_tree(remake_node(nodeAddrArray, _median + 1, numSLLNodes - 1), _depth + 1, 2);
    free(nodeAddrArray);

    return cur;

}


struct kdtree_node *find_way(struct kdtree_node *_root, int _x,int  _y, int axis)
{
    if (axis == 0)
    {
        if (_root->data->x > _x)
            return _root->left;
        else
            return _root->right;
    }
    else
    {
        if (_root->data->y > _y)
            return _root->left;
        else
            return _root->right;
    }
}


int point_search(struct kdtree_node *_root, int _x, int _y)
{
    struct kdtree_node *temp = _root;
    int axis = 0;

    while (1)
    {
        if (temp == 0) // (_x,_y)를 찾지 못했음.
            return 0;

        // 내가 찾고자 하는 값인지 비교
        if (temp->data->x == _x && temp->data->y == _y)
            return 1;

        if (axis == 0) // compare x coordinates
        {
            if (temp->data->x > _x)
                temp = temp->left;
            else
                temp = temp->right;
        }
        else // axis =1 -> compare y coordinates
        {
            if (temp->data->y > _y)
                temp = temp->left;
            else
                temp = temp->right;
        }

        axis = (axis + 1) % 2;//axis 바꿔주기
    }
}

int range_x = 0, range_y = 0;
void range_search(struct kdtree_node *_root, int _x1, int _y1, int _x2, int _y2)
{
    struct kdtree_node *temp = _root;
    int axis = 0;

    while (1)
    {
        if (temp == 0)
            {
            break;
            }

        if ((temp->data->x >= _x1 && temp->data->x <= _x2) && (temp->data->y >= _y1 && temp->data->y <= _y2)) {
            range_x = temp->data->x;
            range_y = temp->data->y;
            break;
        }

        if (axis == 0) // compare x coordinates
        {
            if (temp->data->x > _x2)
                temp = temp->left;
            else
                temp = temp->right;
        }
        else // axis =1 -> compare y coordinates
        {
            if (temp->data->y > _y2)
                temp = temp->left;
            else
                temp = temp->right;
        }

        axis = (axis + 1) % 2;//axis 바꿔주기
    }
}

struct kdtree_node *nearest_neighbor_search(struct kdtree_node *_root,
                                        int _x, int _y,
                                        int _minDiff,
                                        struct kdtree_node * _minDiffNode, int axis, int dim)
{

    if (_root == 0)
        return _minDiffNode;

    if (_root->data->x == _x && _root->data->y == _y)
        return _root;

    else
    {
        int dist = (_root->data->x - _x) *  (_root->data->x - _x) + (_root->data->y - _y)* (_root->data->y - _y);

        if (dist < _minDiff)
        {
            _minDiff = dist;
            _minDiffNode = _root;
        }

        struct kdtree_node *wayTo = find_way(_root, _x, _y, axis%dim);

        struct kdtree_node *NN
                = nearest_neighbor_search(wayTo, _x, _y, _minDiff, _minDiffNode, axis + 1, dim);


        int dist_to_NN = (NN->data->x - _x)*(NN->data->x - _x) + (NN->data->y - _y)*(NN->data->y - _y);

        if (axis%2 == 0)
        {
            if (dist_to_NN > (_x - _root->data->x)*(_x - _root->data->x))
            {
                return nearest_neighbor_search(find_way(_root, _x, _y, axis%dim),
                                           _x, _y, _minDiff, _minDiffNode, axis + 1, dim);
            }
            else
                return NN;
        }
        else
        {
            if (dist_to_NN > (_y - _root->data->y)*(_x - _root->data->x))
            {

                return nearest_neighbor_search(find_way(_root, _x, _y, axis%dim),
                                           _x, _y, _minDiff, _minDiffNode, axis + 1, dim);
            }
            else
                return NN;
        }
    }
}


int main(void)
{

    insert(2, 3);
    insert(5, 4);
    insert(3, 4);
    insert(9, 6);
    insert(4, 7);
    insert(8, 1);
    insert(7, 2);

    kd_root = make_tree(head, 0, 2);


    printf("\n<Point Search>\n");
    if(point_search(kd_root, 5, 4)){
        printf("(5,4) Searched.\n");
    } else printf("(5,4) Not Searched.\n");

    if(point_search(kd_root, 4, 7)){
        printf("(4,7) Searched.\n");
    } else printf("(4,7) Not Searched.\n");

    if(point_search(kd_root, 10, 5)){
        printf("(10,5) Searched.\n");
    } else printf("(10,5) Not Searched.\n");

    printf("\n<Range Search>\n");
    int leftX = 6, leftY = 3;
    int width = 3, height = 4;

    range_search(kd_root, leftX, leftY, leftX + width, leftY + height);
    printf("Range in rectangle : (%d,%d)\n", range_x, range_y);

    printf("\n<Nearest Neighbor Search>\n");
    struct kdtree_node *nns1 = nearest_neighbor_search(kd_root, 5, 4, 10, 0, 0, 2);
    printf("Nearest with (5,4) is (%d,%d)\n", nns1->data->x, nns1->data->y);

    struct kdtree_node *nns2 = nearest_neighbor_search(kd_root, 4, 7, 10, 0, 0, 2);
    printf("Nearest with (4,7) is (%d,%d)\n", nns2->data->x, nns2->data->y);


    return 0;
}
