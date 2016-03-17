package org.news.service;

import org.news.entity.User;
import org.news.exception.UserServiceException;
import org.news.model.UserModel;
import org.springframework.stereotype.Service;
@Service
public interface UserService {
	public void addUser(UserModel user) throws UserServiceException;
	public UserModel getUser(String login, String password) throws UserServiceException;
}
