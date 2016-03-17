package org.news.service;


import static org.news.util.ServiceConverter.convert;
import static org.news.util.ServiceConverter.convertx;

import java.util.Date;

import org.news.dal.IUserDAO;
import org.news.dto.UserDTO;
import org.news.entity.User;
import org.news.exception.UserPersistanceException;
import org.news.exception.UserServiceException;
import org.news.model.UserModel;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
@Service
public class UserServiceImpl implements UserService {
	@Autowired
	private IUserDAO storage;
	
	@Override
	public void addUser(UserModel user) throws UserServiceException {
		// TODO Auto-generated method stub
		try {
			storage.addUser(convert(user));
		} catch (UserPersistanceException e) {
			throw new UserServiceException(e);
		}
	}
	
	public void setStorage(IUserDAO storage) {
		this.storage = storage;
	}

	@Override
	public UserModel getUser(String login, String password)
			throws UserServiceException {
		try {
			return convertx(storage.getUser(login,password));
		} catch (UserPersistanceException e) {
			throw new UserServiceException(e);
		}
	}

}
