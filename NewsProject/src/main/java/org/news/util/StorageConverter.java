package org.news.util;

import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.beanutils.BeanUtils;
import org.news.dto.CategoryDTO;
import org.news.dto.CommentDTO;
import org.news.dto.NewsDTO;
import org.news.dto.UserDTO;
import org.news.entity.Category;
import org.news.entity.Comment;
import org.news.entity.News;
import org.news.entity.User;
import org.news.model.UserModel;

public class StorageConverter {
	public static UserModel currentUser;
	
	public static Category convert(CategoryDTO category) {
		Category ret = new Category();
		try {
			BeanUtils.copyProperties(ret, category);
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
	public static News convert(NewsDTO news) {
		News ret = new News();
		ret.setNewsId(news.getNewsId());
		ret.setBrief(news.getBrief());
		ret.setCategory(convert(news.getCategory()));
		ret.setAuthor(convert(news.getAuthor()));
		ret.setContent(news.getContent());
		ret.setCreated(news.getCreated());
		ret.setLastModified(news.getLastModified());
		ret.setNewsId(news.getNewsId());
		ret.setTitle(news.getTitle());
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
	public static CategoryDTO convert(Category category) {
		CategoryDTO ret = new CategoryDTO();
		//try {
			//BeanUtils.copyProperties(ret, category);
			ret.setCategoryId(category.getCategoryId());
			ret.setCategoryName(category.getCategoryName());
		//} catch (IllegalAccessException | InvocationTargetException e) {
		//	// TODO Auto-generated catch block
		//	e.printStackTrace();
		//}
		return ret;
	}

	public static NewsDTO convert(News news) {
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

			List<CommentDTO> comments = new ArrayList<>();
			for (org.news.entity.Comment comment : news.getComments()) {
				CommentDTO obj = org.news.util.ServiceConverter.convertmd(comment);
				if (obj != null) {
					comments.add(obj);
				}
			}
			ret.setComments(comments);
		return ret;
	}

    /*
	public static CommentDTO convert(Comment comment) {
		CommentDTO ret = new CommentDTO();
		try {
			BeanUtils.copyProperties(ret, comment);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}

	public static Comment convert(CommentDTO comment) {
		Comment ret = new Comment();
		try {
			BeanUtils.copyProperties(ret, comment);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
*/
	public static Comment convert(CommentDTO comment) {
		Comment ret = new Comment();
		try {
			BeanUtils.copyProperties(ret, comment);
		} catch (IllegalAccessException | InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static List<NewsDTO> convert(List<News> list) {
		List<NewsDTO> ret = new ArrayList<>();
		for (News news : list) {
			NewsDTO model = convert(news);
			if (model != null) {
				//model.setstrcreated(model.getCreated().toString());
				ret.add(model);
			}
		}
		return ret;
	}



}
