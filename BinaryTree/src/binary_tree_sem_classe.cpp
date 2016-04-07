#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

template <typename T>
struct Node{
	int key;
	T data;
	Node * left;
	Node * right;
	bool visited;
	int height;

	Node() : key{0}, left{nullptr}, right{nullptr}, visited{false}, height{0}{}
};

/**
*	Método que visita o nó e imprime seu conteudo
**/
template <typename T>
void visitar_raiz(Node<T> * node){
	cout << node->data << " ";
}

/**
*	Método que visita o nó e imprime seu conteudo e sua altura
**/
template <typename T>
void visitar_raiz_com_altura(Node<T> * node){
	cout << node->data << " - Height: " << node->height << endl;
}

/**
*	Percorre a árvore binária usando o método de pré-ordem (RECURSIVO)
**/
template <typename T>
void pre_ordem_recursiva(Node<T> * node){
	if(node != nullptr){
		visitar_raiz(node);

		if(node->left != nullptr){
			pre_ordem_recursiva(node->left);
		}
		if(node->right != nullptr){
			pre_ordem_recursiva(node->right);
		}
	}
}

/**
*	Percorre a árvore binária usando o método de pré-ordem (ITERATIVO)
**/
template <typename T>
void pre_ordem_iterativa(Node<T> * node){
	stack<Node<T>*> pilha;
	pilha.push(node);
	while(!pilha.empty()){
		node = pilha.top();
		pilha.pop();
		visitar_raiz(node);
		if(node->right != nullptr)
			pilha.push(node->right);
		if(node->left != nullptr)
			pilha.push(node->left);		
	}
}

/**
*	Percorre a árvore binária usando o método de ordem simétrica
**/
template <typename T>
void ordem_simetrica_recursiva(Node<T> * node){
	if(node != nullptr){
		if(node->left != nullptr){
			ordem_simetrica_recursiva(node->left);
		}
		visitar_raiz(node);
		if(node->right != nullptr){
			ordem_simetrica_recursiva(node->right);
		}
	}
}

/**
*	Percorre a árvore binária usando o método de ordem simétrica (ITERATIVO)
**/
template <typename T>
void ordem_simetrica_iterativa(Node<T> * node){
	stack<Node<T>*> pilha;
	pilha.push(node);
	Node<T> * node_original = node;
	while(!pilha.empty()){
		node = pilha.top();
		if(node->left == nullptr || node->left->visited == true){
			visitar_raiz(node);
			node->visited = true;
			pilha.pop();
			if(node->right != nullptr && node->right->visited == false){
				pilha.push(node->right);
			}
		}else{
			pilha.push(node->left);
		}		
	}

	node = node_original;
	pilha.push(node);
	while(!pilha.empty()){
		node = pilha.top();
		if(node->left == nullptr || node->left->visited == false){
			node->visited = false;
			pilha.pop();
			if(node->right != nullptr && node->right->visited == true){
				pilha.push(node->right);
			}
		}else{
			pilha.push(node->left);
		}		
	}
}

/**
*	Percorre a árvore binária usando o método de pós-ordem
**/
template <typename T>
void pos_ordem_recursiva(Node<T> * node){
	if(node != nullptr){
		if(node->left != nullptr){
			pos_ordem_recursiva(node->left);
		}
		if(node->right != nullptr){
			pos_ordem_recursiva(node->right);
		}
		visitar_raiz(node);
	}
}

/**
*	Percorre a árvore binária usando o método de pré-ordem (ITERATIVO)
**/
template <typename T>
void pos_ordem_iterativa(Node<T> * node){
	stack<Node<T>*> pilha;
	pilha.push(node);
	Node<T> * node_original = node;
	while(!pilha.empty()){
		node = pilha.top();
		if(node->left == nullptr || node->left->visited == true){
			if(node->right == nullptr || node->right->visited == true){
				visitar_raiz(node);
				node->visited = true;
				pilha.pop();
			}else{
				pilha.push(node->right);
			}
		}else{
			pilha.push(node->left);
		}		
	}

	node = node_original;
	pilha.push(node);
	while(!pilha.empty()){
		node = pilha.top();
		if(node->left == nullptr || node->left->visited == false){
			if(node->right == nullptr || node->right->visited == false){
				node->visited = false;
				pilha.pop();
			}else{
				pilha.push(node->right);
			}
		}else{
			pilha.push(node->left);
		}		
	}
}

/**
*	Percorre a árvore em níveis
**/
template <typename T>
void percorre_em_nivel(Node<T> * node){
	queue<Node<T>*> niveis;
	niveis.push(node);
	while(niveis.size() > 0){
		visitar_raiz(niveis.front());
		if(niveis.front()->left != nullptr) niveis.push(niveis.front()->left);
		if(niveis.front()->right != nullptr) niveis.push(niveis.front()->right);
		niveis.pop();
	}
}

/**
*	Calcula a altura de cada nó
**/
template < typename T>
int calcula_altura_nos(Node<T> * node){
	if(node != nullptr){
		int height = 0;
		if(node->left != nullptr){
			node->height = calcula_altura_nos(node->left);
		}
		if(node->right != nullptr){
			int temp = calcula_altura_nos(node->right);
			if(temp > node->height) node->height = temp;
		}
		node->height++;
		visitar_raiz_com_altura(node);
		return node->height;
	}
}

int main(){

	Node<string> * a = new Node<string>();
	Node<string> * b = new Node<string>();
	Node<string> * c = new Node<string>();
	Node<string> * d = new Node<string>();
	Node<string> * e = new Node<string>();
	Node<string> * f = new Node<string>();
	Node<string> * h = new Node<string>();
	Node<string> * i = new Node<string>();
	Node<string> * j = new Node<string>();
	a->data = "a";
	b->data = "b";
	c->data = "c";
	d->data = "d";
	e->data = "e";
	f->data = "f";
	h->data = "h";
	i->data = "i";
	j->data = "j";

	a->left = b;		
	a->right = c;
	
	b->left = d;
	b->right = h;

	c->left = e;
	c->right = f;

	d->right = j;

	f->left = i;

	cout<<"Pré-ordem: ";
	pre_ordem_iterativa(a);
	cout<<endl;

	cout<<"Ordem simétrica: ";
	ordem_simetrica_iterativa(a);
	cout<<endl;

	cout<<"Pós-ordem: ";
	pos_ordem_iterativa(a);
	cout<<endl;

	cout<<"Hight's tree\n";
	calcula_altura_nos(a);

	cout<<"Em nível: ";
	percorre_em_nivel(a);
	cout<<endl;

	return 0;
}	