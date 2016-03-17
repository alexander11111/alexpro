package org.news.controller;

import org.news.model.UserModel;
import org.springframework.stereotype.Service;
import org.springframework.validation.Errors;
import org.springframework.validation.ValidationUtils;
import org.springframework.validation.Validator;
@Service
public class UserRegsValidator implements Validator {

	@Override
	public boolean supports(Class<?> arg0) {
		// TODO Auto-generated method stub
		return UserModel.class.isAssignableFrom(arg0);
	}

	@Override
	public void validate(Object arg0, Errors arg1) {
		// TODO Auto-generated method stub
		//System.out.println("validate:>>"+arg0);
		
		ValidationUtils.rejectIfEmptyOrWhitespace(arg1, "login",
				"required.user.login", "Field login is required.");

		ValidationUtils.rejectIfEmptyOrWhitespace(arg1, "password",
				"required.user.password", "Field password is required.");

		ValidationUtils.rejectIfEmptyOrWhitespace(arg1, "cpassword",
				"required.user.cpassword", "Field cpassword is required.");	
		
		ValidationUtils.rejectIfEmptyOrWhitespace(arg1, "userName",
				"required.user.userName", "Field userName is required.");	
		
		ValidationUtils.rejectIfEmptyOrWhitespace(arg1, "email",
				"required.user.email", "Field email is required.");	
				
	}

}
