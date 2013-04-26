/*
 *      cl_info.h
 *
 * Copyright 2008-2013 by Aerospike.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#pragma once

#include "cl_types.h"
#include "cluster.h"
#include <sys/socket.h> // socket calls
#include <arpa/inet.h> // inet_ntop
#include <netinet/in.h>

/******************************************************************************
 * FUNCTIONS
 ******************************************************************************/

//
// Use the information system to request data from a given node
// Pass in a '\n' seperated list of names, or no names at all
// [Perhaps a better interface would be an array of pointers-to-names, returning an
//  array of pointers-to-values?]
// Returns a malloc'd string which is the response from the server.
//

int citrusleaf_info(char *host, short port, char *names, char **values, int timeout_ms);
int citrusleaf_info_host(struct sockaddr_in *sa_in, char *names, char **values, int timeout_ms, bool send_asis, bool check_bounds);
int citrusleaf_info_cluster(cl_cluster *asc, char *names, char **values, bool send_asis, bool check_bounds, int timeout_ms);
int citrusleaf_info_cluster_all(cl_cluster * asc, char * names, char ** values, bool send_asis, bool check_bounds, int timeout_ms);