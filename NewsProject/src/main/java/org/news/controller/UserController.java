package org.news.controller;

import java.util.ArrayList;

import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.news.entity.User;
import org.news.exception.NewsServiceException;
import org.news.exception.UserServiceException;
import org.news.model.NewsModel;
import org.news.model.UserModel;
import org.news.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class UserController {
	//private static final Logger log = Logger.getLogger(UserController.class);
	@Autowired
	private UserService service;
	@Autowired
	private UserRegsValidator validator;

	//@RequestMapping(value="userRegistration")
	@RequestMapping(value="userRegistr",method = RequestMethod.GET)
	public String addUser() {
		return "regs";	
	}
	

	//@RequestMapping(value="userAdd",method = RequestMethod.POST)
	@RequestMapping("/userAdd")
	public String userAdd(@ModelAttribute UserModel user,BindingResult result) throws UserServiceException {
		System.out.println("UserController::>"+user.getUserInfo());
		validator.validate(user, result);
		if (result.hasErrors()) {
			return "regs";
		}
		service.addUser(user);
		return "allnews";
	}
	
	@RequestMapping(value="/userLogin",method=RequestMethod.POST)
	@ResponseBody
	public UserModel userLogin(@RequestParam String login, @RequestParam String password,Model model, HttpSession httpSession){
		try {
			UserModel user = (UserModel)service.getUser(login,password);
			if (user==null){httpSession.setAttribute("isAutorized",0); return null;}
			if (user.getLogin()==null) {httpSession.setAttribute("isAutorized",0); return null;} 
			httpSession.setAttribute("isAutorized",1); 
			httpSession.setAttribute("user", user);
			user.setisAutorized(1);
			return user;
		} catch (UserServiceException e) {
			// TODO Auto-generated catch block
		}
		return null;
	}	
	@RequestMapping(value="/userUnLogin",method=RequestMethod.POST)
	public String userUnLogin(HttpSession httpSession) throws UserServiceException {
		httpSession.setAttribute("isAutorized",0);
		httpSession.setAttribute("user",null);
		return "allnews";
	}
	
	@RequestMapping(value="/checkLogin",method=RequestMethod.POST)
	@ResponseBody
	public UserModel checkLogin(HttpSession httpSession){
		UserModel user = (UserModel)httpSession.getAttribute("user");
		if (user==null) return null; 
		if (user.getLogin()==null) return null; 
		return user;
	}	
	

	@ModelAttribute("UserModel")
	public UserModel populateUser() {
		return new UserModel();
	}
	
	public void setService(UserService service) {
		this.service = service;
	}
}
