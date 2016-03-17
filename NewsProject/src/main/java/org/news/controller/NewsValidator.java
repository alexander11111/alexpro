package org.news.controller;

import org.news.model.NewsModel;
import org.springframework.stereotype.Service;
import org.springframework.validation.Errors;
import org.springframework.validation.ValidationUtils;
import org.springframework.validation.Validator;

@Service
public class NewsValidator implements Validator {

	@Override
	public boolean supports(Class<?> clazz) {
		return NewsModel.class.isAssignableFrom(clazz);
	}

	@Override
	public void validate(Object target, Errors errors) {

		ValidationUtils.rejectIfEmptyOrWhitespace(errors, "title",
				"required.news.title", "Field title is required.");

		ValidationUtils.rejectIfEmptyOrWhitespace(errors, "brief",
				"required.news.brief", "Field brief is required.");

		ValidationUtils.rejectIfEmptyOrWhitespace(errors, "content",
				"required.news.content", "Field content is required.");
	}
}
