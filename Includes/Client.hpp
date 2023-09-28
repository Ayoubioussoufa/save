/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:32:08 by aybiouss          #+#    #+#             */
/*   Updated: 2023/09/22 20:32:36 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Webserv.hpp"
#include "Configuration.hpp"
#include "Response.hpp"

class Client
{
    private:
        int         _socketId;
        Configuration   _client_server;
    public : 
        Response    response;
        Client();
        Client(const Client& other);
        Client& operator=(const Client& other);
        const int&          GetSocketId( void ) const;
        const Configuration&      getServer() const;
        void    set_server(Configuration p);
        void    set_socket(int socket);
        ~Client();
};