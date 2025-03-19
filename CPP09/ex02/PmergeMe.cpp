/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:34:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/03/19 14:53:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <typeinfo>

#define RESET "\033[0m"


/**
 * Canonical Form
 */

PmergeMe::PmergeMe(){
    //err = 0;
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
    //err = rhs.err;
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
std::vector<unsigned int>    PmergeMe::getVector() const {
    return _Vector;
}

std::deque<unsigned int>    PmergeMe::getDeque() const {
    return _Deque;
}
//*********************Parsing************************* */
size_t PmergeMe::count_word_and_check(std::string &str) const{
    size_t w = 0;
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        if(str[i] != ' ' && str[i] != '\0'){
            w++;
            while(str[i] != ' ' && str[i] != '\0')
            {
                if(!std::isdigit( str[i]) && str[i] != '+')
                    throw InvalidNumberException();
                i++;
            }
        }
    }
    return w;
}
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
            throw DuplicateValueException();
       _Vector.push_back(n);
       _Deque.push_back(n);
       }
    if(_Vector.size() != count_word_and_check(args_string))
        throw BadInputException();
}
/*******************************Print Results ******************************8 */
void    PmergeMe::print_results(int ac, char **av){
    parsing(ac, av);
    /*if (err == 1)
    {
        std::cout<<"Error: bad input"<<std::endl;
        return;
    }*/
    std::cout << "Before: " << _Vector << std::endl;
    
    std::cout << "\033[34m" << "===============================================================================================" << RESET << std::endl;
    std::cout << "\033[34m" << "**************************************    FJ For VECTOR    ************************************" << RESET << std::endl;
    std::cout << "\033[34m" << "===============================================================================================\n" << RESET << std::endl;
    clock_t startVector = clock();
    fordJohnson(_Vector);
    clock_t endVector = clock();
    std::cout << "\nAfter FJ_Algorithm (Vector) [size: " << getVector().size() << "]\n" << _Vector <<std::endl;


    std::cout << "\033[34m" << "===============================================================================================" << RESET << std::endl;
    std::cout << "\033[34m" << "**************************************    FJ For DEQUE    *************************************" << RESET << std::endl;
    std::cout << "\033[34m" << "===============================================================================================\n" << RESET << std::endl;
    clock_t startDeque = clock();
    fordJohnson(_Deque);
    clock_t endDeque = clock();
    std::cout  << "\nAfter FJ_Algorithm (Deque): [size: " << getDeque().size() << "]\n" <<_Deque << std::endl;

    double timeVector = getElapsedTime(startVector, endVector);
    double timeDeque = getElapsedTime(startDeque, endDeque);

    std::cout << "\033[34m" << "Time to process a range of " << getVector().size() << " elements with std::vector: " << timeVector << " seconds" << RESET << std::endl;
    std::cout << "\033[34m" << "Time to process a range of " << getVector().size() << " elements with std::deque: " << timeDeque << " seconds" << RESET << std::endl << std::endl;
}

void PmergeMe::printPairs(std::vector<std::pair<unsigned int, unsigned int> >& pairs) {
    std::cout << "\033[33m" << "Vector_Pairs: " << RESET ;
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << "); ";
    }
    std::cout << std::endl << std::endl;
}

void PmergeMe::printPairs(std::deque<std::pair<unsigned int, unsigned int> >& pairs) {
    std::cout << "\033[33m" << "Deque_Pairs: " << RESET ;
    for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl << std::endl;
}

void PmergeMe::print_fjSequence(std::vector<unsigned int>& s, unsigned int b_size) 
{
    std::cout << "J_sequence {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691 , ……}" << std::endl;
    std::cout << "last element of J_sequence it has to be <= b_size:" << b_size << std::endl;
    std::cout << "J_sequence: {";
    for (unsigned int i = 0; i < s.size(); ++i) {
        std::cout << s[i];
        if (i+1 < s.size())
            std::cout << ",";
    }
    std::cout << "}\n";
}


void PmergeMe::print_fjSequence(std::deque<unsigned int>& s, unsigned int b_size) 
{
    std::cout << "J_sequence {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691 , ……}" << std::endl;
    std::cout << "last element of J_sequence it has to be <= b_size:" << b_size << std::endl;
    std::cout << "J_sequence: {";
    for (unsigned int i = 0; i < s.size(); ++i) {
        std::cout << s[i];
        if (i+1 < s.size())
            std::cout << ",";
    }
    std::cout << "}\n";
}
/*==============================================       createPairs    ================================================*/



// Function to create pairs from elements ensuring the first is greater than the second (use vector)
std::vector<std::pair<unsigned int, unsigned int> > PmergeMe::createPairs(std::vector<unsigned int>& elements)
{
    std::vector<std::pair<unsigned int, unsigned int> > pairs;

    for (size_t i = 0; i < elements.size(); i += 2) {
        if (i + 1 < elements.size()) {
            pairs.push_back(std::make_pair(elements[i], elements[i + 1]));
        }
    } 
    std::cout << "\033[32m" << "Disjoint Pairs [step(i)]:\n" << RESET;
    printPairs(pairs);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
        {
            int temp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = temp;
        }
    }
    return pairs;
}

// Function to create pairs from elements ensuring the first is greater than the second (use vector)
std::deque<std::pair<unsigned int, unsigned int> > PmergeMe::createPairs(std::deque<unsigned int>& elements)
{
    std::deque<std::pair<unsigned int, unsigned int> > pairs;

    for (size_t i = 0; i < elements.size(); i += 2) {
        if (i + 1 < elements.size()) {
            pairs.push_back(std::make_pair(elements[i], elements[i + 1]));
        }
    } 
    std::cout << "\033[32m" << "Disjoint Pairs [step(i)]:\n" << RESET;
    printPairs(pairs);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
        {
            int temp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = temp;
        }
    }
    return pairs;
}


/*=======================================    binarySearch   ==========================================*/
/**
 * htis function inserts an element into the sorted vector using the binary search
 */
void PmergeMe::binarySearch(std::vector<unsigned int>& sortedVec, unsigned int value) {
    // std::cout << "value: " << value << std::endl;
    size_t low = 0;
    size_t high = sortedVec.size();

    while (low < high) {
        size_t mid = (low + high) / 2;
        if (value < sortedVec[mid])
            high = mid;
        else
            low = mid + 1;
    }
    // Only insert if the value is not already present at the insertion point
     // Shift elements to the right to make space for the new value
    if (low == sortedVec.size() || sortedVec[low] != value) {
        sortedVec.insert(sortedVec.begin() + low, value);
    }
}

// Perform binary insertion to place elements into the sorted deque
void PmergeMe::binarySearch(std::deque<unsigned int>& sortedDeq, unsigned int value)
{
    // std::cout << "value: " << value << std::endl;
    size_t low = 0;
    size_t high = sortedDeq.size();

    while (low < high) {
        size_t mid = (low + high) / 2;
        if (value < sortedDeq[mid])
            high = mid;
        else
            low = mid + 1;
    }
    // Only insert if the value is not already present at the insertion point
    // Shift elements to the right to make space for the new value
    if (low == sortedDeq.size() || sortedDeq[low] != value) {
        sortedDeq.insert(sortedDeq.begin() + low, value);
    }
}

/*==========================================    calculate_Jacobsthal maximum index   ==============================================*/


/*The Ford-Johnson sequence follows a specific recurrence relation:(2^(k+1) + (-1)^k)/3 */
// Function to calculate the maximum Jacobsthal index based on the sequnce size k.
unsigned int Jacobsthal(unsigned int k) {
    unsigned int sec = (k % 2 == 0) ? 1 : -1;
    unsigned int tk = round(((1 << (k + 1)) + sec )/ 3);
    return tk;
}

/*===========================================      insert Uncools       ======================================================*/


// Function to insert ucool elements of b into the main chain of cool VECTOR elements
void PmergeMe::insertUncools(std::vector<unsigned int>& a, std::vector<unsigned int>& b)
{
    unsigned int size_b = b.size();

    // Generate the correct Jacobsthal sequence (start from 1 and that means first element in uncools)
    std::vector<unsigned int> J_sequence;

    // Generate Ford-Johnson sequence
    for (unsigned int k = 1; ; ++k)
    {
        unsigned int tk = Jacobsthal(k);
        if (tk > size_b) {
            break;
        }
        J_sequence.push_back(tk);
    }

    print_fjSequence(J_sequence, size_b);

    std::cout << "\n*** " << "1" << "\033[32m" << "'th element in b already added in the mainChain:" << RESET << b[0] << " ***" << std::endl;
    // Inserting uncool elements based on the defined order
    // Loop through the t_sequence
    for (unsigned int J_index = 1; J_index < J_sequence.size(); ++J_index) {
        unsigned int J_s = J_sequence[J_index];
        unsigned int J_s_minus_1 = (J_index > 0) ? J_sequence[J_index - 1] : 0;
        
        // Insert b_tk, b_(tk-1), ..., b_(tk-1+1) into the main chain
        for (unsigned int i = J_s; i > J_s_minus_1; --i) {
            if (i <= b.size()) {
                std::cout << i << "\033[32m" << "'th element in b added in the mainChain: "  << RESET << b[i - 1]<< std::endl;
                binarySearch(a, b[i - 1]); // (i - 1) because we have different index order, Jacobsthal starts at 1 and the vector starts at 0.
            }
        }
    }

    // Insert any remaining elements from uncool b that are not covered by the sequence start from the last element of b
    std::cout << "\nadd the rest elements of b_vector" << std::endl;
    if(b[size_b - 1])
        for (size_t j = size_b ; j > J_sequence[J_sequence.size()-1];)
        {
            std::cout << j << "\033[32m" << "'th element in b to add in mainChain: " << RESET  << b[j - 1] << std::endl;
            binarySearch(a, b[j - 1]);
            j--;
        }
       
}

// Function to insert ucool elements of b into the main chain of cool elements a when deque container is used
void PmergeMe::insertUncools(std::deque<unsigned int>& a, std::deque<unsigned int>& b)
{
    unsigned int size_b = b.size();

    // Generate the correct Jacobsthal sequence (start from 1 and that means first element in uncools)
    std::vector<unsigned int> J_sequence;

    // Generate Ford-Johnson sequence
    for (unsigned int k = 1; ; ++k)
    {
        unsigned int tk = Jacobsthal(k);
        if (tk > size_b) {
            break;
        }
        J_sequence.push_back(tk);
    }

    print_fjSequence(J_sequence, size_b);

    std::cout << "\n*** " << "1" << "\033[32m" << "'th element in b already added in the mainChain:" << RESET << b[0] << " ***" << std::endl;
    // Inserting uncool elements based on the defined order
    // Loop through the t_sequence
    for (unsigned int J_index = 1; J_index < J_sequence.size(); ++J_index) {
        unsigned int J_s = J_sequence[J_index];
        unsigned int J_s_minus_1 = (J_index > 0) ? J_sequence[J_index - 1] : 0;
        
        // Insert b_tk, b_(tk-1), ..., b_(tk-1+1) into the main chain
        for (unsigned int i = J_s; i > J_s_minus_1; --i) {
            if (i <= b.size()) {
                std::cout << i << "\033[32m" << "'th element in b added in the mainChain: "  << RESET << b[i - 1]<< std::endl;
                binarySearch(a, b[i - 1]); // (i - 1) because we have different index order, Jacobsthal starts at 1 and the vector starts at 0.
            }
        }
    }

    // Insert any remaining elements from uncool b that are not covered by the sequence start from the last element of b
    std::cout << "\nadd the rest elements of b_vector" << std::endl;
    if(b[size_b - 1])
        for (unsigned int j = size_b ; j > J_sequence[J_sequence.size()-1];)
        {
            std::cout << j << "\033[32m" << "'th element in b to add in mainChain: " << RESET  << b[j - 1] << std::endl;
            binarySearch(a, b[j - 1]);
            j--;
        }
       
}
/*==============================================       merge      ==================================================*/



// Function to merge the two parts of the vector
void PmergeMe::merge(std::vector<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int mid, unsigned int right)
{
    unsigned int leftSize = mid - left + 1;
    unsigned int rightSize = right - mid;

    std::vector<std::pair<unsigned int, unsigned int> > leftPairs(leftSize);
    std::vector<std::pair<unsigned int, unsigned int> > rightPairs(rightSize);

    for (size_t i = 0; i < leftSize; ++i) {
        leftPairs[i] = pairs[left + i];
    }
    for (size_t j = 0; j < rightSize; ++j) {
        rightPairs[j] = pairs[mid + 1 + j];
    }

    // std::cout << "left pairs in merge:\n";
    // printPairsV(leftPairs);
    // std::cout << "right pairs in merge:\n";
    // printPairsV(rightPairs);

    // Merge the temporary arrays back into pairs[left..right]
    unsigned int i = 0; 
    unsigned int j = 0; 
    unsigned int k = left;
    while (i < leftSize && j < rightSize) {
        if (leftPairs[i] < rightPairs[j]) {
            pairs[k] = leftPairs[i];
            i++;
        } else {
            pairs[k] = rightPairs[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        pairs[k] = leftPairs[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        pairs[k] = rightPairs[j];
        j++;
        k++;
    }
}
// Function to merge the two parts of the deque
void PmergeMe::merge(std::deque<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int mid, unsigned int right)
{
    unsigned int leftSize = mid - left + 1;
    unsigned int rightSize = right - mid;

    std::deque<std::pair<unsigned int, unsigned int> > leftPairs(leftSize);
    std::deque<std::pair<unsigned int, unsigned int> > rightPairs(rightSize);

    for (size_t i = 0; i < leftSize; ++i) {
        leftPairs[i] = pairs[left + i];
    }
    for (size_t j = 0; j < rightSize; ++j) {
        rightPairs[j] = pairs[mid + 1 + j];
    }

    // std::cout << "left pairs in merge:\n";
    // printPairsV(leftPairs);
    // std::cout << "right pairs in merge:\n";
    // printPairsV(rightPairs);

    // Merge the temporary arrays back into pairs[left..right]
    unsigned int i = 0; 
    unsigned int j = 0; 
    unsigned int k = left;
    while (i < leftSize && j < rightSize) {
        if (leftPairs[i] < rightPairs[j]) {
            pairs[k] = leftPairs[i];
            i++;
        } else {
            pairs[k] = rightPairs[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        pairs[k] = leftPairs[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        pairs[k] = rightPairs[j];
        j++;
        k++;
    }
}
/*============================================       mergeSort         ==========================================*/


// Function to perform merge sort on pairs
void PmergeMe::mergeSort(std::vector<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int right) {
    if (left < right) 
    {
        unsigned int mid = left + (right - left) / 2;

        mergeSort(pairs, left, mid); // left half
        mergeSort(pairs, mid + 1, right); // right half
        merge(pairs, left, mid, right);
    }
}




// Function to perform merge sort on pairs
void PmergeMe::mergeSort(std::deque<std::pair<unsigned int, unsigned int> >& pairs, unsigned int left, unsigned int right) {
    if (left < right)
    {
        unsigned int mid = left + (right - left) / 2;

        mergeSort(pairs, left, mid);
        mergeSort(pairs, mid + 1, right);
        merge(pairs, left, mid, right);
    }
}

/*============================================          time          ==========================================*/


double PmergeMe::getElapsedTime(const std::clock_t start, const std::clock_t end) {
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

/*============================================      fordJohnson        ================================================*/


// Ford-Johnson Sorting Algorithm (using vector)
void PmergeMe::fordJohnson(std::vector<unsigned int>& vec) 
{
    if (vec.size() <= 1)
        return;

    size_t n = vec.size();
    std::vector<unsigned int> a, b;

 
    /*i) Make pairwise comparisons of [n/2] disjoint pairs of elements. (If n is odd, leave one element out.)*/

	//turn the container into pairs
    std::vector<std::pair<unsigned int, unsigned int> > pair_vector = createPairs(vec);
    
    std::cout << "\033[32m" << "Pairwise comparison [step(i)]:\n" << RESET;
    printPairs(pair_vector);

    /*ii) Sort the [n/2] larger numbers, found in step (i), by merge insertion.*/
   // Sort pairs using Merge-Insertion Sort based on the first element
    mergeSort(pair_vector, 0, pair_vector.size() - 1);

    std::cout << "\033[32m" << "sort the larger elements by mergeSort [step(ii)]:\n" << RESET;
    printPairs(pair_vector);



    /*iii) Name the elements a1, a2, ... , a[n/2], b1, b2, ... , b[n/2] , where a1 <= a2 <= ... <= a[n/2] and bi <= ai for 1 <= i <= [ n/2 ]; call b1 and the a's the
    "main chain." " Insert the remaining b's into the main chain, using binary insertion, in the following order, leaving out all bj for j > [n/2]*/
    for (size_t i = 0; i < pair_vector.size(); ++i) {
        a.push_back(pair_vector[i].first); // Add the first element of the pair to vector a
        b.push_back(pair_vector[i].second); // Add the second element of the pair to vector b
    }
 
 
    std::cout << "\033[32m"<< "Name the elements a1,a2,... which a1<=a2<=...<=a[n/2](sorted) [step(iii)]\n" << "A_Vector: " << a << RESET << std::endl;
    std::cout << std::endl;
    // If odd, append the last element to b
    if (n % 2 != 0) {
        std::cout << "add the last element in b vector (because the size of our elements is odd)!" <<  std::endl;
        b.push_back(vec[n - 1]);
    }
    std::cout << "\033[32m" << "Name the elements b1,b2,... which b1<=b2<=...<=b[n/2](unsorted) [step(iii)]\n" <<  "B_Vector: " << b << RESET << std::endl;
    std::cout << std::endl;


    /* call b1 and the a's the "main chain."*/
    std::vector<unsigned int> mainChain;
    mainChain.push_back(b[0]);  // Start with b1
    mainChain.insert(mainChain.end(), a.begin(), a.end());
    std::cout << "\033[32m" << "call b1 and the a's the main chain [step(iii)]:\n" << "mainChain_Vector: " << mainChain << RESET << std::endl;
    std::cout << std::endl;

    insertUncools(mainChain, b);

    vec.clear();
    vec.insert(vec.end(), mainChain.begin(), mainChain.end());
}

// Ford-Johnson Sorting Algorithm (using deque)
void PmergeMe::fordJohnson(std::deque<unsigned int>& vec) 
{
    if (vec.size() <= 1)
        return;

    size_t n = vec.size();
    std::deque<unsigned int> a, b;

 
    /*i) Make pairwise comparisons of [n/2] disjoint pairs of elements. (If n is odd, leave one element out.)*/

	//turn the container into pairs
    std::deque<std::pair<unsigned int, unsigned int> > pair_deque = createPairs(vec);
    
    std::cout << "\033[32m" << "Pairwise comparison [step(i)]:\n" << RESET;
    printPairs(pair_deque);

    /*ii) Sort the [n/2] larger numbers, found in step (i), by merge insertion.*/
   // Sort pairs using Merge-Insertion Sort based on the first element
    mergeSort(pair_deque, 0, pair_deque.size() - 1);

    std::cout << "\033[32m" << "sort the larger elements by mergeSort [step(ii)]:\n" << RESET;
    printPairs(pair_deque);



    /*iii) Name the elements a1, a2, ... , a[n/2], b1, b2, ... , b[n/2] , where a1 <= a2 <= ... <= a[n/2] and bi <= ai for 1 <= i <= [ n/2 ]; call b1 and the a's the
    "main chain." " Insert the remaining b's into the main chain, using binary insertion, in the following order, leaving out all bj for j > [n/2]*/
    for (size_t i = 0; i < pair_deque.size(); ++i) {
        a.push_back(pair_deque[i].first); // Add the first element of the pair to deque a
        b.push_back(pair_deque[i].second); // Add the second element of the pair to deque b
    }
 
 
    std::cout << "\033[32m"<< "Name the elements a1,a2,... which a1<=a2<=...<=a[n/2](sorted) [step(iii)]\n" << "A_deque: " << a << RESET << std::endl;
    std::cout << std::endl;
    // If odd, append the last element to b
    if (n % 2 != 0) {
        std::cout << "add the last element in b deque (because the size of our elements is odd)!" <<  std::endl;
        b.push_back(vec[n - 1]);
    }
    std::cout << "\033[32m" << "Name the elements b1,b2,... which b1<=b2<=...<=b[n/2](unsorted) [step(iii)]\n" <<  "B_deque: " << b << RESET << std::endl;
    std::cout << std::endl;


    /* call b1 and the a's the "main chain."*/
    std::deque<unsigned int> mainChain;
    mainChain.push_back(b[0]);  // Start with b1
    mainChain.insert(mainChain.end(), a.begin(), a.end());
    std::cout << "\033[32m" << "call b1 and the a's the main chain [step(iii)]:\n" << "mainChain_deque: " << mainChain << RESET << std::endl;
    std::cout << std::endl;

    insertUncools(mainChain, b);

    vec.clear();
    vec.insert(vec.end(), mainChain.begin(), mainChain.end());
}

