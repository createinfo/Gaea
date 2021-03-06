/*
 *  Copyright Beijing 58 Information Technology Co.,Ltd.
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 *  specific language governing permissions and limitations
 *  under the License.
 */
/*
 * SocketPool.h
   *
 * Created on: 2011-7-5
 * Author: Service Platform Architecture Team (spat@58.com)
 */

#ifndef SOCKETPOOL_H_
#define SOCKETPOOL_H_
#include "SocketPoolProfile.h"
#include <pthread.h>
#include <list>
namespace gaea {
class SocketPool {
public:
	SocketPool(char *hostName, int port, SocketPoolProfile *config);
	virtual ~SocketPool();
	int getSocket();
	void releaseSocket(int fd);
	void closeSocket(int fd);
	void closeAllSocket();
private:
	std::list<int> *csocketQueue;
	pthread_mutex_t queueMutex;
	size_t maxPoolSize;
	size_t minPoolSize;
	char *hostName;
	int port;
	size_t minFreeCount;
	size_t socketCount;
	time_t lastCheckTime;
	int shrinkInterval;
	SocketPoolProfile *config;
	int queuePop();
};
}
#endif /* SOCKETPOOL_H_ */

