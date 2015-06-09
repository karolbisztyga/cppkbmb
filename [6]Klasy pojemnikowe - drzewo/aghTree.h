#ifndef AGHTREE_H
#define AGHTREE_H

template<class T>
class aghTree : public aghContainer<T> {
private:
	aghTreeItem<T> *root;
	void print(aghTreeItem<T>*);
public:
	virtual ~aghTree();
	aghTree();
	aghTree(const aghTree&);
	aghTree(aghContainer<T>&);
	bool insert(int, T const&);
	T& at(int) const;
	int size() const;
	bool remove(int);
	void print();
    aghTreeItem<T>* iterate(int) const;

	aghTree<T>& operator=(aghTree<T> const& element);
	aghTree<T>& operator=(aghContainer<T> const& element);
	bool operator==(aghContainer<T> const& element);
	bool operator!=(aghContainer<T> const& element);
};


/* */
/// \brief constructor no params
///
///
template<class T>
aghTree<T>::aghTree() {
	this->root = NULL;
}
/* */
/// \brief destructor
///
///
template<class T>
aghTree<T>::~aghTree() {
	this->clear();
}
/* */
/// \brief constructor copy
///
/// \param v - tree to be copied
template<class T>
aghTree<T>::aghTree(const aghTree<T> &t) {
	this->root = NULL;
	for( int i=0 ; i<t.size() ; ++i ) {
		this->append(t.at(i));
	}
}
/* */
/// \brief constructor copy
///
/// \param c - container to br copied
template<class T>
aghTree<T>::aghTree(aghContainer<T> &c) {
	this->root = NULL;
	for( int i=0 ; i<c.size() ; ++i ) {
		this->append(c.at(i));
	}
}
/* */
/// \brief inserts element in tree
///
/// \param index - where is the element meant to be
/// \param t - element to be added
///
/// \return bool
///		true - inserting successful
///		false - inserting unsuccessful
template<class T>
bool aghTree<T>::insert(int index, T const &t) {
	aghTreeItem<T> *item = new aghTreeItem<T>(t);
	if( this->root == NULL ) {
		this->root = item;
		return true;
	}
	aghTreeItem<T> *temp = this->root;
	while( temp != NULL ) {
		if( temp->getValue() < item->getValue() ) {
			if( temp->getRight() == NULL ) {
				temp->setRight(item);
				item->setParent(temp);
				return true;
			}
			temp = temp->getRight();
		} else {
			if( temp->getLeft() == NULL ) {
				temp->setLeft(item);
				item->setParent(temp);
				return true;
			}
			temp = temp->getLeft();
		}
	}
	return false;
}

/// \brief returns vector's element on given index
///
/// \param index - index of an element
///
/// \return T& - element's value reference
template<class T>
T& aghTree<T>::at(int index) const {
	return this->iterate(index)->getValue();
}

/// \brief returns vector's size
///
///
/// \return int - size of the vector
template<class T>
int aghTree<T>::size() const {
	int i = 0;
	aghTreeItem<T> *temp = this->root;
    aghVector<aghTreeItem<T>*> *vector = new aghVector<aghTreeItem<T>*>();
    while( (vector->size() > 0) || temp != NULL ) {
        if( temp != NULL ) {
            vector->append(temp);
            temp = temp->getLeft();
        }
        else {
            temp = vector->at(vector->size()-1);
            vector->remove(vector->size() - 1);
            ++i;
            temp = temp->getRight();
        }
    }
    delete vector;
    return i;
}

/// \brief removes element from vector
///
/// \param index - index of an element
///
/// \return bool
///		true - element existed and has been removed
///		false - there wasn't such element
template <class T>
bool aghTree<T>::remove(int index){
	if (index < 0 || index >= this->size())
		return false;
 
	aghTreeItem<T> *item_to_remove = iterate(index);
	if (item_to_remove->getLeft() == NULL && item_to_remove->getRight() == NULL){ //if element don't have children (leaf)
		if (item_to_remove == this->root){
			delete this->root;
			this->root = 0;
			return true;
		}
 
		if (item_to_remove->getParent()->getLeft() == item_to_remove)
			item_to_remove->getParent()->setLeft(NULL);
		if (item_to_remove->getParent()->getRight() == item_to_remove)
			item_to_remove->getParent()->setRight(NULL);
		delete item_to_remove;
		item_to_remove = NULL;
		return true;
	}
	if (item_to_remove->getLeft() != NULL && item_to_remove->getRight() == NULL){ //if element have only left child
		if (item_to_remove == this->root){
			this->root = item_to_remove->getLeft();
			delete this->root->getParent();
			this->root->setParent(NULL);
			return true;
		}
		aghTreeItem<T> *prev_item = item_to_remove->getParent();
		if (prev_item->getLeft() == item_to_remove){
			prev_item->setLeft(item_to_remove->getLeft());
			delete item_to_remove;
			prev_item->getLeft()->setParent(prev_item);
		}
		if (prev_item->getRight() == item_to_remove){
			prev_item->setRight(item_to_remove->getLeft());
			delete item_to_remove;
			prev_item->getRight()->setParent(prev_item);
		}
		return true;
	}
	if (item_to_remove->getLeft() == NULL && item_to_remove->getRight() != NULL){ //if element have only right child
		if (item_to_remove == this->root){
			this->root = item_to_remove->getRight();
			delete this->root->getParent();
			this->root->setParent(NULL);
			return true;
		}
		aghTreeItem<T> *prev_item = item_to_remove->getParent();
		if (prev_item->getLeft() == item_to_remove){
			prev_item->setLeft(item_to_remove->getRight());
			delete item_to_remove;
			prev_item->getLeft()->setParent(prev_item);
		}
		if (prev_item->getRight() == item_to_remove){
			prev_item->setRight(item_to_remove->getRight());
			delete item_to_remove;
			prev_item->getRight()->setParent(prev_item);
		}
		return true;
	}
	//if element have two children
	aghTreeItem<T> *smallest_item = iterate(index + 1);
	item_to_remove->setValue(smallest_item->getValue());
	return remove(index + 1);
}
/// \brief assigment operator
///
/// \param aghTree - vector to be copied
///
/// \return aghTree<T>& - vector's reference
template<class T>
aghTree<T>& aghTree<T>::operator=(aghTree<T> const& tree) {
	if( this->operator!=(tree) ) {
		this->aghContainer<T>::operator=(tree);
	}
}

/// \brief assigment operator
///
/// \param aghTree - container to be copied
///
/// \return aghTree<T>& - vector's reference
template<class T>
aghTree<T>& aghTree<T>::operator=(aghContainer<T> const& con) {
	if( this->operator!=(con) ) {
		this->aghContainer<T>::operator=(con);
	}
}

/// \brief comparing operator
///
/// \param aghContainer - vector to be compared
///
/// \return bool
///		true - containers are the same
///		false - containers are different
template<class T>
bool aghTree<T>::operator==(aghContainer<T> const& element) {
	return this->aghContainer<T>::operator==(element);
}

/// \brief comparing operator
///
/// \param aghContainer - vector to be compared
///
/// \return bool
///		true - containers are different
///		false - containers are the same
template<class T>
bool aghTree<T>::operator!=(aghContainer<T> const& element) {
	return this->aghContainer<T>::operator!=(element);
}

template<class T>
aghTreeItem<T>* aghTree<T>::iterate(int index) const{
    aghVector<aghTreeItem<T>*> vector;
    aghTreeItem<T>* temp = this->root;
    int i = 0;
    while( (vector.size() > 0) || temp != NULL ) {
        if( temp != NULL ){
            vector.append(temp);
            temp = temp->getLeft();
        }
        else {
            temp = vector.at(vector.size()-1);
            vector.remove(vector.size()-1);
            if(i == index) {
            	return temp;
            }
            ++i;
            temp = temp->getRight();
        }
    }
    throw aghException(0, "Index out of range", __FILE__, __LINE__);
}


template<class T>
void aghTree<T>::print(){
	this->print(this->root);
}

template<class T>
void aghTree<T>::print(aghTreeItem<T> *branch){
	if( branch == NULL ) {
		return;
	}
	this->print(branch->getLeft());
	cout << "["<< branch->getValue() <<"]" ;
	this->print(branch->getRight());
}

#endif
