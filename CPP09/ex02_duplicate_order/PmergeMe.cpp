/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:34:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/18 15:12:01 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <typeinfo>
/**
 * Canonical Form
 */

PmergeMe::PmergeMe(){
}

size_t PmergeMe::count_word_and_check(std::string &str) const{
    int w = 0;
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        if(str[i] != ' ' && str[i] != '\0'){
            w++;
            while(str[i] != ' ' && str[i] != '\0')
            {
                if(!std::isdigit( str[i]) && str[i] != '+')
                    throw "bad trip";
                i++;
            }
        }
    }
    return w;
}


/*PmergeMe::PmergeMe(std::vector<unsigned int> vect){
    std::vector<unsigned int>::iterator it;
    for (it = vect.begin(); it != vect.end(); it++){
        _Vector.push_back(*it);
        _Deque.push_back(*it);
    }
}*/

PmergeMe::PmergeMe(PmergeMe const & src){
    *this = src;
}

PmergeMe&   PmergeMe::operator=(PmergeMe const & rhs){
    this->_Deque = rhs.getDeque();
    this->_Vector = rhs.getVector();
    this->_endV = rhs._endV;
    this->_endD = rhs._endD;
    this->_startV = rhs._startV;
    this->_startD = rhs._startD;
    return *this;
}

PmergeMe::~PmergeMe(){
    
}
// *************************print vector elements*************************
std::ostream&   operator<<(std::ostream &os, std::vector<unsigned int> & obj){
    for (std::vector<unsigned int>::iterator it = obj.begin(); it < obj.end(); ++it) {
        os << *it << " ";
    }
    
    return os;
}
// *************************print deque elements*************************
std::ostream&   operator<<(std::ostream &os, std::deque<unsigned int> & obj){
    for (std::deque<unsigned int>::iterator it = obj.begin(); it < obj.end(); ++it) {
        os << *it << " ";
    }
    
    return os;
}
//*********************** */ Getters***************************
std::vector<unsigned int>   PmergeMe::getVector() const {
    return _Vector;
}

std::deque<unsigned int>   PmergeMe::getDeque() const {
    return _Deque;
}
//*********************Parsing************************* */
void    PmergeMe::parsing(int ac, char **av){
    
    std::string args_string ;
    for (int i = 1 ; i < ac; i++){
        args_string += av[i] ;
        if(av[i] != NULL)
            args_string += " ";   
    }
    std::istringstream ss(args_string);
    unsigned int  n;
    while(ss >> n){
        if (std::find(_Vector.begin(), _Vector.end(), n) != _Vector.end())
            throw std::runtime_error("Duplicate value detected");
       _Vector.push_back(n);
       _Deque.push_back(n);
       }
    if(_Vector.size() != count_word_and_check(args_string))
        throw "bad inputs";
}
/*******************************Print Results ******************************8 */
void    PmergeMe::print_results(int ac, char **av){
    parsing(ac, av);
    std::cout << "Before: " << _Vector << std::endl;
    sorting(_Deque);
    sorting(_Vector);
    std::cout << "After: " << _Vector << std::endl;
    
    sort_timeV();
    sort_timeD();
}


void PmergeMe::sorting(){
    sorting(_Vector);
    sorting(_Deque);
}
//******************** */ Ford Jonhson for vectors*********************************
void    PmergeMe::sorting(std::vector<unsigned int> & vec){
    static int order = 1;
    if(order == 1)
        _startV = clock();
    int unit_size = vec.size() / order;
    if (unit_size < 2) return;

    bool is_odd = unit_size % 2 == 1;
    std::vector<unsigned int>::iterator start = vec.begin();
    std::vector<unsigned int>::iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));

    for (std::vector<unsigned int>::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }

    order *= 2;
    sorting(vec);
    order /= 2;

    std::vector<unsigned int> cool; //the higher elements in pairs
    std::vector<unsigned int> uncool; // the lower elements in pairs
    unsigned int odd = 0;
    std::vector<unsigned int> left;

    cool.push_back(*(start + order - 1));
    cool.push_back(*(start + order * 2 - 1));

    for (std::vector<unsigned int>::iterator it = start + order * 2; it < end; it += order) {
        uncool.push_back(*(it + order - 1));
        it += order;
        cool.push_back(*(it + order - 1));
    }

    if (is_odd) odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), vec.end());

    if (is_odd || !uncool.empty()) 
        insert(cool, uncool, odd, left, vec, is_odd, order);
    if(order == 1)
        _endV = clock();
    
}
//******************** */ Ford Jonhson for deques*********************************
void    PmergeMe::sorting(std::deque<unsigned int> & vec){
    static int order = 1;
    if(order == 1)
        _startD = clock();
    int unit_size = vec.size() / order;
    if (unit_size < 2) return;

    bool is_odd = unit_size % 2 == 1;
    std::deque<unsigned int>::iterator start = vec.begin();
    std::deque<unsigned int>::iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));

    for (std::deque<unsigned int>::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }

    order *= 2;
    sorting(vec);
    order /= 2;

    std::deque<unsigned int> cool; //the higher elements in pairs
    std::deque<unsigned int> uncool; // the lower elements in pairs
    unsigned int odd = 0;
    std::deque<unsigned int> left;

    cool.push_back(*(start + order - 1));
    cool.push_back(*(start + order * 2 - 1));

    for (std::deque<unsigned int>::iterator it = start + order * 2; it < end; it += order) {
        uncool.push_back(*(it + order - 1));
        it += order;
        cool.push_back(*(it + order - 1));
    }

    if (is_odd) odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), vec.end());

    if (is_odd || !uncool.empty()) 
        insert(cool, uncool, odd, left, vec, is_odd, order);
    if(order == 1)
        _endD = clock();
    
}


/** Compute the Jacobsthal index, where to insert the uncool element 
 * within the cool elements */

int PmergeMe::Jacobsthal(int k){
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}
/******************************************************************************** */
/**
 * ***************************Binary search*****************************
 */
int PmergeMe::binary_search(std::vector<unsigned int > &vecteur, unsigned int b)
{
    int start = 0;
    int end = vecteur.size()-1;
    int mid;
    while(start<=end)
    {
        mid = start + (end - start) /2;
        if (vecteur[mid] ==b)
            return mid;
        if(b > vecteur[mid])
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
        
    }
    return start;
}
/********************************************************************************
/**
 * cool : is the higher integer in the pairs
 * uncool : is the lower integers in the pairs
 * is_odd : if the container is odd 
 */
void PmergeMe::insert(std::vector<unsigned int> &cool, std::vector<unsigned int> &uncool, unsigned int odd, std::vector<unsigned int> &left, std::vector<unsigned int> &vec, bool is_odd, unsigned int order){
    std::vector<unsigned int>::iterator    end;
    /**
     * Here I should implement the binary search instead of upper_bound !!!!****** 
     */
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
    std::vector<unsigned int>   result;
    if (is_odd){
        end = std::upper_bound(cool.begin(), cool.end(), odd);
        cool.insert(end, odd);
    }
    for (std::vector<unsigned int>::iterator j = cool.begin(); j != cool.end(); j++) {
        std::vector<unsigned int>::iterator it = std::find(vec.begin(), vec.end(), *j);
        result.insert(result.end(), it - (order -1), it + 1);
    }
    result.insert(result.end(), left.begin(), left.end());
    vec = result;
}
/**
 * insert for deque structure
 */
void PmergeMe::insert(std::deque<unsigned int> &cool, std::deque<unsigned int> &uncool, unsigned int odd, std::deque<unsigned int> &left, std::deque<unsigned int> &vec, bool is_odd, unsigned int order){
    std::deque<unsigned int>::iterator    end;
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
    std::deque<unsigned int>   result;
    if (is_odd){
        end = std::upper_bound(cool.begin(), cool.end(), odd);
        cool.insert(end, odd);
    }
    for (std::deque<unsigned int>::iterator j = cool.begin(); j != cool.end(); j++) {
        std::deque<unsigned int>::iterator it = std::find(vec.begin(), vec.end(), *j);
        result.insert(result.end(), it - (order -1), it + 1);
    }
    result.insert(result.end(), left.begin(), left.end());
    vec = result;
}


float   PmergeMe::timeV(){    
    return static_cast<float>(_endV - _startV) / CLOCKS_PER_SEC;   
}
float   PmergeMe::timeD(){    
    return static_cast<float>(_endD - _startD) / CLOCKS_PER_SEC;   
}

void    PmergeMe::sort_timeV(){
    float elapsedTime = timeV();
    std::cout << "Time to process a range of " << _Vector.size() << " elements with vector" << " : " << std::fixed << std::setprecision(6) << elapsedTime << " s" << std::endl;   
}
void    PmergeMe::sort_timeD(){
    float elapsedTime = timeD();
    std::cout << "Time to process a range of " << _Deque.size() << " elements with deque" << " : " << std::fixed << std::setprecision(6) << elapsedTime << " s" << std::endl;   
}

