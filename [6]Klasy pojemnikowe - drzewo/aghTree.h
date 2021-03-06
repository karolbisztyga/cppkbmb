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
bool aghTree<T>::remove(int index) {
	if(index < 0 || index >= this->size()) {
		return false;
	}
	aghTreeItem<T> *rm = iterate(index);
	//no children
	if(rm->getLeft() == NULL && rm->getRight() == NULL) {
		if(rm == this->root) {
			delete this->root;
			this->root = 0;
			return true;
		}
 
		if(rm->getParent()->getLeft() == rm) {
			rm->getParent()->setLeft(NULL);
		}
		if(rm->getParent()->getRight() == rm) {
			rm->getParent()->setRight(NULL);
		}
		delete rm;
		rm = NULL;
		return true;
	}
	//one child
	if(rm->getLeft() == NULL || rm->getRight() == NULL) {
		if(rm == this->root) {
			this->root = ( rm->getLeft() == NULL ) ? rm->getRight() : rm->getLeft();
			delete this->root->getParent();
			this->root->setParent(NULL);
			return true;
		}
		aghTreeItem<T> *pt = rm->getParent();
		if(pt->getLeft() == rm) {
			if( rm->getLeft() == NULL ) {
				pt->setLeft(rm->getRight());
			} else {
				pt->setLeft(rm->getLeft());
			}
			delete rm;
			pt->getLeft()->setParent(pt);
		}
		if(pt->getRight() == rm) {
			if( rm->getLeft() == NULL ) {
				pt->setRight(rm->getRight());
			} else {
				pt->setRight(rm->getLeft());
			}
			delete rm;
			pt->getRight()->setParent(pt);
		}
		return true;
	}
	//two children = recursive!
	aghTreeItem<T> *sit = iterate(index + 1);
	rm->setValue(sit->getValue());
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
        if( temp != NULL ) {
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
void aghTree<T>::print() {
	this->print(this->root);
}

template<class T>
void aghTree<T>::print(aghTreeItem<T> *branch) {
	if( branch == NULL ) {
		return;
	}
	this->print(branch->getLeft());
	cout << "["<< branch->getValue() <<"]" ;
	this->print(branch->getRight());
}

#endif
