	#include <iostream>
	template<class T>
	class list
	{
	private:
		list *next;
		T value;
	public:
		list();
		//добавляет элемент
		void add(T val);
		//удаляет элемент
		void del(T val);
		void printAll();
		//печатает все элементы, которые соответсвуют условию, описанному в функции
		//pr
		template<typename Predictor>
		void printAllWhere(Predictor pr);
		T popBack();
		~list();
	};
	//реализация
	//class list
	template<class T>
	list<T>::list() : next(NULL)
	{
	}
	template<class T>
	void list<T>::add(T val)
	{
		if (!next)
		{
			next = new list<T>();
			next->value = val;
		}
		else
		{
			next->add(val);
		}
	}
	template<class T>
	void list<T>::del(T val)
	{
		if (!next)
			return;
		if (next->value == val)
		{
			list<T> *temp = next;
			next = temp->next;
			temp->next = NULL;
			delete temp;
		}
		else
			next->del(val);
	}
	template<class T>
	void list<T>::printAll()
	{
		value.print();
		if (next)
			next->printAll();
	}

	template<class T>
	template <typename Predictor>
	void list<T>::printAllWhere(Predictor pr)
	{
		if (pr(value))
			value.print();
		if (next)
			next->printAllWhere(pr);
	}
	template<class T>
	T list<T>::popBack()
	{
		if (!next)
			throw "Empty list";
		if (next->next == NULL)
		{
			T last = next->value;
			delete next;
			next = NULL;
			return last;
		}
		return next->popBack();
	}
	template<class T>
	list<T>::~list()
	{
 		if(next)
			delete next;
	}

