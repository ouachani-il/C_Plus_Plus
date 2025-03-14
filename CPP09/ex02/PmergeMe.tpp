/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:34:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/14 15:50:04 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"
#include <typeinfo>

template <typename Container>
std::ostream&   operator<<(std::ostream &os, PmergeMe<Container> & cont){
    typename Container::iterator it;
    for (it = cont.begin(); it < cont.end(); ++it) {
        os << *it << " ";
    }
    return os;
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::begin(){
    return container.begin();
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::end(){
    return container.end();
}

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv){
    std::string args_string;
    for (int i = 1; i < argc; i++){
        int element = std::atoi(argv[i]);
        if ( element <= 0){
            throw std::runtime_error("Error: negativ input detected. Please provide only positive integers.");
        }
        args_string.push_back(element);    
    }
    if (hasDoubles(input_integers))
        throw std::runtime_error("Error: doubles are detected.");        

}

template <typename Container>
bool    PmergeMe<Container>::hasDoubles(std::vector<int>& set){
    std::vector<int>    vect; // the vector where to put the unique elements
    std::vector<int>::iterator  it;
    
    for (it = set.begin(); it != set.end(); it++){
        if (std::find(vect.begin(), vect.end(), *it) != vect.end()){
            std::cerr << "Error : Duplicated integer found." << *it << std::endl;
            return true;
        }
        vect.push_back(*it);
        
    }
    return false;
}

template <typename Container>
void PmergeMe<Container>::sorting(){
    sorting(container);
}
template <typename Container>
PmergeMe<Container>::PmergeMe(){

}

template <typename Container>
void    PmergeMe<Container>::sorting(Container & vec){
    static int order = 1;
    if(order == 1)
        _start = clock();
    int unit_size = vec.size() / order;
    if (unit_size < 2) return;

    bool is_odd = unit_size % 2 == 1;
    Iterator start = vec.begin();
    Iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));

    for (Iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }

    order *= 2;
    sorting(vec);
    order /= 2;

    Container cool; //the higher elements in pairs
    Container uncool; // the lower elements in pairs
    ValueType odd = 0;
    Container left;

    cool.push_back(*(start + order - 1));
    cool.push_back(*(start + order * 2 - 1));

    for (Iterator it = start + order * 2; it < end; it += order) {
        uncool.push_back(*(it + order - 1));
        it += order;
        cool.push_back(*(it + order - 1));
    }

    if (is_odd) odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), vec.end());

    if (is_odd || !uncool.empty()) 
        insert(cool, uncool, odd, left, vec, is_odd, order);
    if(order == 1)
        _end = clock();
    
}
template <typename Container>
std::string PmergeMe<Container>::container_type(){
    if(typeid(container) == typeid(std::vector<typename Container::value_type>))
        return "std::vector";
    else if (typeid(container) == typeid(std::deque<typename Container::value_type>)){
        return "std::deque";
    }else if (typeid(container) == typeid(std::list<typename Container::value_type>)){
        return "std::list";
    }
    return "bad trip";
}
/**
 * cool : is the higher integer in the pairs
 * uncool : is the lower integers in the pairs
 * is_odd : if the container is odd 
 */
template <typename Container>
void PmergeMe<Container>::insert(Container &cool, Container &uncool, ValueType odd, Container &left, Container &vec, bool is_odd, int order){
    Iterator    end;
    if (uncool.size() == 1) // only one element in the uncool set
    {
        end = std::upper_bound(cool.begin(), cool.end(), *uncool.begin());
        cool.insert(end, *uncool.begin());
    }
    else if (uncool.size() > 1) //here we use Jacobsthal series since the elements number >=2
    {
        size_t  jc = 3; // we start at index 3 in Jacobsthal series
        size_t  count = 0;
        size_t  idx;
        size_t  decrease;
        while ( !uncool.empty()){
            idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if (idx > uncool.size())
                idx = uncool.size();
            decrease = 0;
            while (idx){
                end = cool.begin();
                if (Jacobsthal(jc + count) - decrease <= cool.size())
                    end = cool.begin() + Jacobsthal(jc + count) - decrease;
                else
                    end = cool.end();
                end = std::upper_bound(cool.begin(), end, *(uncool.begin() + idx -1));
                cool.insert(end, *(uncool.begin() + idx -1));
                uncool.erase(uncool.begin() + idx - 1);
                idx--;
                decrease++;
                count++;
                
            }
            jc++;
        }
    }
    Container   result;
    if (is_odd){
        end = std::upper_bound(cool.begin(), cool.end(), odd);
        cool.insert(end, odd);
    }
    for (Iterator j = cool.begin(); j != cool.end(); j++) {
        Iterator it = std::find(vec.begin(), vec.end(), *j);
        result.insert(result.end(), it - (order -1), it + 1);
    }
    result.insert(result.end(), left.begin(), left.end());
    vec = result;
}

template <typename Container>
float   PmergeMe<Container>::time(){    
    return static_cast<float>(_end - _start) / CLOCKS_PER_SEC;   
}

template <typename Container>
void    PmergeMe<Container>::sort_time(){
    float elapsedTime = time();
    std::cout << "Time to process a range of " << container.size() << " elements with " << container_type() << " : " << std::fixed << std::setprecision(6) << elapsedTime << " s" << std::endl;   
}

/*template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container> const & src){
    
}

template <typename Container>
PmergeMe<Container>&   PmergeMe<Container>::operator=(PmergeMe<Container> const & rhs){
    
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(){
    
}*/






