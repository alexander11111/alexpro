package org.news.service;

import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.news.dal.INewsDAO;
import org.news.dao.NewsHibernateDAOMock;
import org.news.model.NewsModel;

import static org.junit.Assert.*;

public class NewsServiceTestMockUp {

	private static INewsDAO storage;
	private static NewsServiceImpl service;

	@BeforeClass
	public static void classSetup() {
		storage = new NewsHibernateDAOMock();

		service = new NewsServiceImpl();
		service.setStorage(storage);
	}

	@Before
	public void init() {

	}

	@After
	public void destroy() {
		((NewsHibernateDAOMock) storage).clean();
	}

	@Test
	public void test2() throws Exception {
		NewsModel model = new NewsModel();
		model.setNewsId(10);
		service.addNews(model);
		assertEquals(1, service.getNewsList().size());
		assertEquals(service.getNewsList().size(),
				((NewsHibernateDAOMock) storage).newsList.size());
		assertEquals(10, service.getNews(10).getNewsId());
		assertNotNull(service.getNews(10).getCreated());
		assertNotNull(service.getNews(10).getLastModified());
	}

	@Test
	public void test() {
		assertTrue(true);
	}
}
