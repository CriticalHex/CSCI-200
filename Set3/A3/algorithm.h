#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>

std::vector<uint32_t>::iterator max_element(std::vector<uint32_t>::iterator,
                                            std::vector<uint32_t>::iterator);
std::vector<uint32_t>::iterator min_element(std::vector<uint32_t>::iterator,
                                            std::vector<uint32_t>::iterator);
std::vector<std::string>::iterator find(std::vector<std::string>::iterator,
                                        std::vector<std::string>::iterator,
                                        std::string);

#endif // ALGORITHM_H