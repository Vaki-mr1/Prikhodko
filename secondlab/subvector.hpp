struct subvector {
     int *mas;
     unsigned int top; 
     unsigned int capacity;
};

bool init(subvector *qv);
bool resize(subvector *qv, unsigned int new_capacity);
bool push_back(subvector *qv, int d);
int pop_back(subvector *qv);
void shrink_to_fit(subvector *qv);
void clear(subvector *qv);
void destructor(subvector *qv);