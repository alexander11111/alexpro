package org.news.controller;

import java.util.Date;
import java.util.List;

import static org.news.util.ServiceConverter.*;

import javax.servlet.http.HttpSession;




import org.apache.log4j.Logger;
import org.news.dto.NewsDTO;
import org.news.dto.UserDTO;
import org.news.entity.Category;
import org.news.entity.User;
import org.news.exception.NewsServiceException;
import org.news.model.CategoryMod;
import org.news.model.Comment;
import org.news.model.CommentResp;
import org.news.model.NewsModel;
import org.news.model.NewsResponse;
import org.news.model.UserModel;
import org.news.service.NewsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;



@Controller
public class NewsController {
	//private static final Logger log = Logger.getLogger(NewsController.class);
	@Autowired
	private NewsService service;

	@Autowired
	private NewsValidator validator;
	
	@RequestMapping("/list1/{id}")
	@ResponseBody
	public List<NewsModel> listNews(@PathVariable int id,HttpSession httpSession) {
		List<NewsModel> newsList = null;
		try {
			
			UserModel user = (UserModel)httpSession.getAttribute("user");
			if (user==null) httpSession.setAttribute("isAutorized",0);else 
			if (user.getLogin()==null) httpSession.setAttribute("isAutorized",0);else
				httpSession.setAttribute("isAutorized",1); 
						
			if (id==4)newsList = service.getNewsList();else
			newsList = service.getNewsCat(id);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return newsList;
	}
	
	@RequestMapping(value = "deleteNews/{userName}/{id}", method = RequestMethod.POST)
	@ResponseBody
	public NewsResponse delNews(@PathVariable String userName,@PathVariable long id,HttpSession httpSession) {
		NewsResponse res = new NewsResponse();
		res.setparam0(0);
		try {
			UserModel user = (UserModel)httpSession.getAttribute("user");
			if(user==null) res.setparam0(1);else
				if (userName.equals(user.getUserName())==false) res.setparam0(3);else
			       service.delNews(id);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			res.setparam0(2);
		}
		return res;
	}

	@RequestMapping(value = "deleteComment/{userName}/{commentId}", method = RequestMethod.POST)
	@ResponseBody
	public NewsResponse deleteComment(@PathVariable String userName,@PathVariable long commentId,HttpSession httpSession) {
		NewsResponse res = new NewsResponse();
		res.setparam0(0);
		try {
			UserModel user = (UserModel)httpSession.getAttribute("user");
			if(user==null) res.setparam0(1);
			else
			{
			 service.delCommentID(commentId);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			res.setparam0(2);
		}
		return res;
	}

	
	@RequestMapping("/list")
	public String getNewsList(Model model) {
		//try {
			//List<NewsModel> list = service.getNewsList();
			//List<NewsModel> list = service.getNewsCat(3);
			//model.addAttribute("newsList", list);
		//} catch (NewsServiceException e) {
			//log.error(e);
		//}
		return "allnews";
	}

	@RequestMapping(value = "newsAdd", method = RequestMethod.POST)
	@ResponseBody
	public String addNews(@ModelAttribute NewsModel newsModel,@RequestParam String categoryID,
			                              BindingResult result,
			                              HttpSession httpSession){
		CategoryMod category = new CategoryMod();
		if ("undefined".equals(categoryID)==true) categoryID="0"; 
		category.setCategoryId(Long.valueOf(categoryID));
		newsModel.setCategory(category);
		
		
		UserModel user = (UserModel)httpSession.getAttribute("user");
		newsModel.setAuthor(user);
		
		validator.validate(newsModel, result);
		
        System.out.println("NewsController::>AddNews USER: "+user.getUserInfo());
        System.out.println("NewsController::>AddNews News: "+newsModel.getNewsInfo());
        
		if (result.hasErrors()) {
			return "0";
		}
        
		try {
			service.addNews(newsModel);
		} catch (NewsServiceException e) {
			 System.out.println("NewsController::>Error:Write! ");
			//log.error(e);
			return "0";
		}

		return "1";
	}

	@RequestMapping(value = "news/view/{id}")
	public String viewNews(@PathVariable int id, Model model,HttpSession httpSession) {
		try {
			NewsModel news = service.getNews(id);
			model.addAttribute("news", news);
			httpSession.setAttribute("news",news);
		} catch (NewsServiceException e) {
			//log.error(e);
		}
		return "view";
	}
	

	@RequestMapping(value = "newsOneView/{id}")
	public String newsOneView(@PathVariable int id, Model model,HttpSession httpSession) {
		try {
			NewsModel news = service.getNews(id);
			//model.addAttribute("news", news);
			UserModel user = (UserModel)httpSession.getAttribute("user");
			if (user==null) news.setisAutorized(0);else
			if (user.getLogin()==null) news.setisAutorized(0);else
				                       news.setisAutorized(1);      
			httpSession.setAttribute("news",news);
		} catch (NewsServiceException e) {
		}
		return "news";
	}
	
	@RequestMapping(value = "updateNewsData")
	@ResponseBody
	public NewsModel urlupdateNewsData(HttpSession httpSession) {
		try {
			NewsModel news = (NewsModel)httpSession.getAttribute("news");
			if (news==null) return null;
			NewsModel newsData = service.getNews(news.getNewsId());
			httpSession.setAttribute("news",newsData);
			return newsData;
		} catch (NewsServiceException e) {
			//log.error(e);
			return null;
		}
	}
	
	@RequestMapping(value = "addComment", method = RequestMethod.POST)
	@ResponseBody
	public CommentResp addComment(@RequestParam String email,
			                 @RequestParam String password,
			                 @RequestParam String comment,
			                 HttpSession httpSession){
		UserModel user = (UserModel)httpSession.getAttribute("user");
		NewsModel news = (NewsModel)httpSession.getAttribute("news");
	
		CommentResp comeResp = new CommentResp();
		/*System.out.println("NewsController::>addComment Comment:"
				+ " email:"+email
				+ " password:"+comment
				+ " comment:"+comment
				+ " newsID:"+news.getNewsId()
				+ " category:"+news.getCategory().getCategoryId());
        */
		comeResp.setsavestate(0);
		comeResp.setcategoryId(news.getCategory().getCategoryId());
		comeResp.setnewsId(news.getNewsId());
		
		Comment comm = new Comment();
		comm.setAuthor(user);
		comm.setNews(news); 
		comm.setCreated(new Date());
		comm.setMessage(comment);

		try {
			if (service.checkUser(email,password)==false){
				comeResp.setsavestate(1);
				return comeResp;
			}
			comeResp.setcommentId(service.addComment(comm));
			comeResp.setuserName(user.getUserName());
			comeResp.setstrcreated(comm.getCreated().toString());
		} catch (NewsServiceException e) {
			comeResp.setsavestate(2);
			return null;
		}
		return comeResp;
	}

	@RequestMapping(value = "news/add/page", method = RequestMethod.GET)
	public String addPage() {
		return "add";
	}
	
	@RequestMapping(value="userRegistrationReflect",method = RequestMethod.GET)
	public String addUser() {

		return "regs";	
	}
	
	@RequestMapping(value="newsAddReflect",method = RequestMethod.GET)
	public String addNews() {
		return "addnews";	
	}
	
 
	
	public void setService(NewsService service) {
		this.service = service;
	}
	


	
	@ModelAttribute("newsModel")
	public NewsModel populateUser() {
		return new NewsModel();
	}
}
