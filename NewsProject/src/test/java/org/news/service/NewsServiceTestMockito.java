package org.news.service;

import org.junit.BeforeClass;
import org.junit.Test;
import org.news.dal.INewsDAO;
import org.news.dal.NewsHibernateDAOImpl;
import org.news.model.NewsModel;

import static org.mockito.Mockito.*;
import static org.junit.Assert.*;

public class NewsServiceTestMockito {

	private static INewsDAO storage;
	private static NewsServiceImpl service;

	@BeforeClass
	public static void init() {
		storage = mock(NewsHibernateDAOImpl.class);

		service = new NewsServiceImpl();
		service.setStorage(storage);
	}

	@Test
	public void test2() throws Exception {
		service.addNews(new NewsModel());
		assertEquals(1, service.getNewsList().size());
	}

	@Test
	public void test() {
		assertTrue(true);
	}
}
