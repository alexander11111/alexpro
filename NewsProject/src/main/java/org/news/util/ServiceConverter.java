package org.news.util;

import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.beanutils.BeanUtils;
import org.news.dto.CategoryDTO;
import org.news.dto.CommentDTO;
import org.news.dto.NewsDTO;
import org.news.dto.UserDTO;
import org.news.entity.News;
import org.news.entity.User;
import org.news.model.CategoryMod;
import org.news.model.Comment;
import org.news.model.NewsModel;
import org.news.model.UserModel;

public class ServiceConverter {

	public static CategoryDTO convert(CategoryMod category) {
		//if (category==null) 
		CategoryDTO ret = new CategoryDTO();
		try {
			BeanUtils.copyProperties(ret, category);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static NewsDTO convert(NewsModel news) {
		NewsDTO ret = new NewsDTO();
		ret.setNewsId(news.getNewsId());
		ret.setBrief(news.getBrief());
		ret.setCategory(convert(news.getCategory()));
		ret.setAuthor(convert(news.getAuthor()));
		ret.setContent(news.getContent());
		ret.setCreated(news.getCreated());
		ret.setLastModified(news.getLastModified());
		ret.setNewsId(news.getNewsId());
		ret.setTitle(news.getTitle());
		ret.setstrcreated(ret.getCreated().toString());
		return ret;
	}
	
	public static CategoryMod convert(CategoryDTO category) {
		CategoryMod ret = new CategoryMod();
		ret.setCategoryId(category.getCategoryId());
		ret.setCategoryName(category.getCategoryName());
		return ret;
	}
	public static UserModel convert_0(UserDTO user) {
		UserModel ret = new UserModel();
		try {
			BeanUtils.copyProperties(ret, user);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static NewsModel convert(NewsDTO news) {
		NewsModel ret = new NewsModel();
		ret.setNewsId(news.getNewsId());
		ret.setBrief(news.getBrief());
		//news.getCategory();
		ret.setCategory(convert(news.getCategory()));
		ret.setAuthor(convert_0(news.getAuthor()));
		ret.setContent(news.getContent());
		ret.setCreated(news.getCreated());
		ret.setLastModified(news.getLastModified());
		ret.setNewsId(news.getNewsId());
		ret.setTitle(news.getTitle());
		ret.setstrcreated(ret.getCreated().toString());

		List<Comment> comments = new ArrayList<>();
		for (CommentDTO comment : news.getComments()) {
			Comment obj = convert_dto_model(comment);
			obj.setstrcreated(news.getCreated().toString());
			if (obj != null) {
				comments.add(obj);
			}
		}
		ret.setComments(comments);
		
		return ret;
	}

	public static List<NewsModel> convert(List<NewsDTO> list) {
		List<NewsModel> ret = new ArrayList<>();
		for (NewsDTO news : list) {
			NewsModel model = convert(news);
			if (model != null) {
				
				ret.add(model);
			}
		}
		return ret;
	}

	public static UserDTO convert(User user) {
		UserDTO ret = new UserDTO();
		try {
			BeanUtils.copyProperties(ret, user);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}

	public static User convert(UserDTO user) {
		User ret = new User();
		try {
			BeanUtils.copyProperties(ret, user);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static UserDTO convert(UserModel user) {
		UserDTO ret = new UserDTO();
		try {
			BeanUtils.copyProperties(ret, user);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static NewsDTO convert_comm(News news) {
		NewsDTO ret = new NewsDTO();
		    ret.setNewsId(news.getNewsId());
			//ret.setBrief(news.getBrief());
			//ret.setCategory(convert(news.getCategory()));
			//ret.setAuthor(convert(news.getAuthor()));
			//ret.setContent(news.getContent());
			//ret.setCreated(news.getCreated());
			//ret.setLastModified(news.getLastModified());
			//ret.setNewsId(news.getNewsId());
			//ret.setTitle(news.getTitle());
			//ret.setstrcreated(ret.getCreated().toString());
		return ret;
	}

	public static CommentDTO convertmd(org.news.entity.Comment comment) {
		CommentDTO ret = new CommentDTO();
		ret.setAuthor(convert(comment.getAuthor()));
		//ret.setNews(convert_comm(comment.getNews()));
		ret.setCommentId(comment.getCommentId());
		ret.setCreated(comment.getCreated());
		ret.setMessage(comment.getMessage());
		return ret;
	}
	public static org.news.entity.Comment convertmd(CommentDTO comment) {
		org.news.entity.Comment ret = new org.news.entity.Comment();
		ret.setAuthor(convert(comment.getAuthor()));
		ret.setNews(org.news.util.StorageConverter.convert(comment.getNews()));
		ret.setCreated(comment.getCreated());
		ret.setMessage(comment.getMessage());
		return ret;
	}
	
	public static CommentDTO convertmd(org.news.model.Comment comment) {
		CommentDTO ret = new CommentDTO();
		ret.setAuthor(convert(comment.getAuthor()));
		ret.setNews(convert(comment.getNews()));
		ret.setCreated(comment.getCreated());
		ret.setMessage(comment.getMessage());
		return ret;
	}
	public static News convertx0(NewsDTO news) {
		return org.news.util.StorageConverter.convert(news);
	}
	public static org.news.entity.Comment convert(CommentDTO comment) {
		org.news.entity.Comment ret = new org.news.entity.Comment();
		ret.setAuthor(convert(comment.getAuthor()));
		ret.setNews(convertx0(comment.getNews()));
		ret.setCreated(comment.getCreated());
		ret.setMessage(comment.getMessage());
		return ret;
	}
	
	public static org.news.model.Comment convert_dto_model(CommentDTO comment) {
		org.news.model.Comment ret = new org.news.model.Comment();
		ret.setAuthor(convert_0(comment.getAuthor()));
		//ret.setNews(convert(comment.getNews()));
		ret.setCommentId(comment.getCommentId());
		ret.setCreated(comment.getCreated());
		ret.setMessage(comment.getMessage());
		return ret;
	}
	
	public static UserModel convertx(UserDTO user) {
		UserModel ret = new UserModel();
		try {
			BeanUtils.copyProperties(ret, user);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
}
