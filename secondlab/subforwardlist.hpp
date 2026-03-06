struct subforwardlist {
    int data;
    subforwardlist* next;
};

bool init(subforwardlist **sfl);
bool push_forward(subforwardlist **sfl, int d);
int pop_forward(subforwardlist **sfl);
bool push_back(subforwardlist **sfl, int d);
int pop_back(subforwardlist **sfl);
unsigned int size(subforwardlist **sfl);
bool push_where(subforwardlist **sfl, unsigned int where, int d);
int erase_where(subforwardlist **sfl, unsigned int where);
void clear(subforwardlist **sfl);