/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:22:11 by ilouacha          #+#    #+#             */
/*   Updated: 2025/02/28 22:02:24 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
#include <list>

int	main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top : "<<mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size : "<<mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout<<"print stack"<<std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout<<"***************"<<std::endl;
        while (!s.empty())
        {
            std::cout<<s.top()<<std::endl;
            s.pop();
        }
    }
    std::cout<<std::endl<<"************list************"<<std::endl;
    {
        std::list<int> m_list;
        m_list.push_back(5);
        m_list.push_back(17);
        std::cout << "top "<<m_list.front() << std::endl;
        m_list.pop_back();
        std::cout << "size "<<m_list.size() << std::endl;
        m_list.push_back(3);
        m_list.push_back(5);
        m_list.push_back(737);
        m_list.push_back(0);
        std::list<int>::iterator it = m_list.begin();
        std::list<int>::iterator ite = m_list.end();
        ++it;
        --it;
        std::cout<<"print stack"<<std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int, std::list<int> > s(m_list);
        std::cout<<"***************"<<std::endl;
         while (!s.empty())
        {
            std::cout<<s.top()<<std::endl;
            s.pop();
        }
    }

    {
        MutantStack<int> mutantStack;
        for (int i = 0; i < 5; ++i)
        {
            mutantStack.push(i);
        }

        std::cout << "simple iterator ";
        for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
        {
            std::cout << *it << " ";
        }

        std::cout << std::endl<<"const iterator : ";
        for (MutantStack<int>::const_iterator cit = mutantStack.cbegin(); cit != mutantStack.cend(); ++cit)
        {
            std::cout << *cit << " ";
        }

        std::cout << std::endl<<"reverse iterator ";
        for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it)
        {
            std::cout << *it << " ";
        }

        std::cout << std::endl << "const reverse iterator ";
        for (MutantStack<int>::const_reverse_iterator rit = mutantStack.crbegin(); rit != mutantStack.crend(); ++rit)
        {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;

    }
    return 0;
}