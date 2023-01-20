#include <iostream>
#include <algorithm>
#include <memory>
#include <iterator>

template <typename ValueType>
class ForwardList {
    class ListNode;
    using NodPtr = std::shared_ptr<ListNode>;
public:
    class ListIterator;
public:
    ForwardList():_first(nullptr), _last(nullptr){}
    void PushBack(const ValueType& value){
        if(!_first){
            _first = std::make_shared<ListNode>(value);
            _last = _first;
        } else {
            _last->AddNext(value);
            _last = _last->GetNext();
        }
    }
    std::shared_ptr<ListNode> GetFirst() {
         return _first;
    }
    std::shared_ptr<ListNode> GetLast() {
        return _last;
    }
     ListIterator begin(){
        return ListIterator(_first);
     }
     ListIterator end()
     {
        return ListIterator(_last->GetNext());
     }
    ~ForwardList() = default;
private:
    std::shared_ptr<ListNode> _first;
    std::shared_ptr<ListNode> _last;

public:
    class ListIterator: public std::iterator<std::forward_iterator_tag, ValueType>{
        public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = ValueType;
        using reference = ValueType&;
        using pointer = ValueType*;
        using difference_type = int;

        ListIterator():_node(nullptr){}
        ListIterator(std::shared_ptr<ListNode> node):_node(node){};
        ValueType& operator* ()
        {
            return _node->GetData();
        }
        ListIterator& operator++() {
            _node = _node->GetNext();
            return *this;
        }

        bool operator != (const ListIterator& other) const {
            return _node != other._node;
        }
        private:
            std::shared_ptr<ListNode> _node;
    };
private:
    class ListNode{
    public:
        ListNode(const ValueType& data):_data(data), _next(nullptr){}
        void AddNext(const ValueType& data){
            _next = std::make_shared<ListNode>(data);
        }
        std::shared_ptr<ListNode> GetNext()const {return _next;}
        ValueType& GetData() {return _data;}
    private:
        ValueType _data;
        std::shared_ptr<ListNode> _next;
    };
};

int main() {
    ForwardList<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    auto first = list.begin();

    std::for_each(list.begin(), list.end(), [](int i){ std::cout<<i << std::endl; });

    std::for_each(list.begin(), list.end(), [](int& i){ i++; std::cout<<i; });

    auto found = std::find_if(list.begin(), list.end(), [] (int i){return i > 3; });
    auto it = list.begin();
    std::advance(it, 3);
    auto distance = std::distance(list.begin(), it);
    std::cout<<">>>>>"<<distance<<std::endl;
}