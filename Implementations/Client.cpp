/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:32:21 by aybiouss          #+#    #+#             */
/*   Updated: 2023/09/22 20:32:50 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Client.hpp"

Client::Client() {}

void    Client::set_server(Configuration p)
{
    _client_server = p;
}
void    Client::set_socket(int socket)
{
    _socketId = socket;
}

const int& Client::GetSocketId( void ) const
{       
    return (_socketId);
}

Client::Client(const Client& other)
{
    if (this != &other)
    {
        this->_socketId = other._socketId;
        this->_client_server = other._client_server;
    }
}

Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        this->_socketId = other._socketId;
        this->_client_server = other._client_server;
        this->response = other.response;
    }
    return *this;
}

const Configuration&      Client::getServer( void ) const
{
    return (_client_server);
}

Client::~Client() {}