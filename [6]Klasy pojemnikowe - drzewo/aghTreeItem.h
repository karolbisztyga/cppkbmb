#ifndef AGHTREEITEM_H
#define AGHTREEITEM_H
	
template<class T>
class aghTreeItem {
	public:
		aghTreeItem(const T&);

		void setRight(aghTreeItem<T>*);
		aghTreeItem *getRight() const;

		aghTreeItem *getLeft() const;
		void setLeft(aghTreeItem<T>*);
		
		void setParent(aghTreeItem<T>*);
		aghTreeItem *getParent() const;

		T& getValue();
		void setValue(const T&);
	private:
		aghTreeItem *right, *left, *parent;
		T value;
};

template<class T>
aghTreeItem<T>::aghTreeItem(const T &value) {
	this->right = NULL;
	this->left = NULL;
	this->parent = NULL;
	this->value = value;
}

template<class T>
void aghTreeItem<T>::setRight(aghTreeItem<T> *item) {
	this->right = item;
}

template<class T>
void aghTreeItem<T>::setParent(aghTreeItem<T> *item) {
	this->parent = item;
}

template<class T>
void aghTreeItem<T>::setLeft(aghTreeItem<T> *item) {
	this->left = item;
}

template<class T>
aghTreeItem<T> *aghTreeItem<T>::getRight() const {
	return this->right;
}

template<class T>
aghTreeItem<T> *aghTreeItem<T>::getParent() const {
	return this->parent;
}

template<class T>
aghTreeItem<T> *aghTreeItem<T>::getLeft() const {
	return this->left;
}

template<class T>
T& aghTreeItem<T>::getValue() {
	return this->value;
}

template<class T>
void aghTreeItem<T>::setValue(const T &value) {
	this->value = value;
} 

#endif